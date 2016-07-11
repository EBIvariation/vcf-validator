/**
 * Copyright 2016 EMBL - European Bioinformatics Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <memory>
#include <iostream>

#include "catch/catch.hpp"

#include "vcf/record_cache.hpp"
#include "test_utils.hpp"

namespace ebi
{
    size_t count_duplicates_and_rethrow_error(vcf::RecordCache &cache, TestMultiRecord summary)
    {
        try {
            return cache.check_duplicates(build_mock_record(summary)).size();
        } catch (vcf::BodySectionError * e) {
          // Catch doesn't seem to understand an exception thrown by a pointer. workaround to see the message: rethrow by value
            throw *e;
        }
    }

    TEST_CASE("RecordCache tests: capacity==1")
    {
        vcf::RecordCache cache{1};

        cache.check_duplicates(build_mock_record({100, "A", {"T"}}));

        SECTION("there's no duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {101, "A", {"T"}}) == 0 );
        }
        SECTION("no duplicate detected because capacity is too small") {
            CHECK( count_duplicates_and_rethrow_error(cache, {101, "A", {"T"}}) == 0 );
            // This is not going to throw because capacity is 1, we would need a bigger cache.
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 0 );
        }

        SECTION("one simple duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "A", {"T"}}) == 2 );
        }
        SECTION("one multiallelic duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("triplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 2 );
            // triplicate missed, reported as duplicate
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT"}}) == 2 );
        }
    }

    TEST_CASE("RecordCache tests: capacity==5")
    {
        vcf::RecordCache cache{5};

        cache.check_duplicates(build_mock_record({100, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({101, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({102, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({103, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({104, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({105, "A", {"T"}}));

        SECTION("there's no duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {106, "A", {"T"}}) == 0 );
        }
        SECTION("no duplicate detected because capacity is too small") {
            // This is not going to throw because capacity is 1, we would need a bigger cache.
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 0 );
        }

        SECTION("one simple duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {103, "A", {"T"}}) == 2 );
        }
        SECTION("one multiallelic duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("triplicate")
        {
            CHECK( count_duplicates_and_rethrow_error(cache, {104, "GA", {"GT", "C"}}) == 2 );
            // the first occurrence should not be reported again
            CHECK( count_duplicates_and_rethrow_error(cache, {104, "GA", {"GT"}}) == 1 );
        }
    }

    TEST_CASE("RecordCache tests: unlimited capacity")
    {
        vcf::RecordCache cache{0};

        cache.check_duplicates(build_mock_record({100, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({101, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({102, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({103, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({104, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({105, "A", {"T"}}));

        SECTION("there's no duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {106, "A", {"T"}}) == 0 );
        }

        SECTION("duplicate detected because there's no capacity limitation") {
            // This is not going to throw because capacity is 1, we would need a bigger cache.
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("one simple duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {103, "A", {"T"}}) == 2 );
        }
        SECTION("one multiallelic duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("triplicate")
        {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT", "C"}}) == 2 );
            // the first occurrence should not be reported again
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT"}}) == 1 );
        }
    }
}
