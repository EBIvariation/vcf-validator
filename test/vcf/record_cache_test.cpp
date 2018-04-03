/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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
            cache.check_duplicates(build_mock_record(summary));
            return cache.get_duplicates().size();
        } catch (vcf::BodySectionError * e) {
          // Catch doesn't seem to understand an exception thrown by a pointer. workaround to see the message: rethrow by value
            throw *e;
        }
    }

    size_t count_symbolic_duplicates_and_rethrow_error(vcf::RecordCache &cache, TestMultiRecord summary)
    {
        try {
            cache.check_duplicates(build_mock_record(summary));
            return cache.get_symbolic_duplicates().size();
        } catch (vcf::BodySectionError * e) {
          // Catch doesn't seem to understand an exception thrown by a pointer. workaround to see the message: rethrow by value
            throw *e;
        }
    }

    TEST_CASE("RecordCache tests: capacity==1")
    {
        vcf::RecordCache cache{1};

        cache.check_duplicates(build_mock_record({100, "A", {"T"}}));

        SECTION("There's no duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {101, "A", {"T"}}) == 0 );
        }
        SECTION("No duplicate detected because capacity is too small") {
            CHECK( count_duplicates_and_rethrow_error(cache, {101, "A", {"T"}}) == 0 );
            // This is not going to throw because capacity is 1, we would need a bigger cache.
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 0 );
        }

        SECTION("One simple duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "A", {"T"}}) == 2 );
        }
        SECTION("One multiallelic duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("Triplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 2 );
            // triplicate missed, reported as duplicate
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT"}}) == 2 );
        }
        SECTION("Symbolic Duplicates")
        {
            CHECK( count_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 0 );
            // This won't throw an error. 
            CHECK( count_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 0 );
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

        SECTION("There's no duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {106, "A", {"T"}}) == 0 );
        }
        SECTION("No duplicate detected because capacity is too small") {
            // This is not going to throw because capacity is 1, we would need a bigger cache.
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 0 );
        }

        SECTION("One simple duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {103, "A", {"T"}}) == 2 );
        }
        SECTION("One multiallelic duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("Triplicate")
        {
            CHECK( count_duplicates_and_rethrow_error(cache, {104, "GA", {"GT", "C"}}) == 2 );
            // the first occurrence should not be reported again
            CHECK( count_duplicates_and_rethrow_error(cache, {104, "GA", {"GT"}}) == 1 );
        }
        SECTION("Symbolic Duplicates")
        {
            CHECK( count_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 0 );
            // This won't throw an error.
            CHECK( count_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 0 );
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

        SECTION("There's no duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {106, "A", {"T"}}) == 0 );
        }

        SECTION("Duplicate detected because there's no capacity limitation") {
            // This is not going to throw because capacity is 1, we would need a bigger cache.
            CHECK( count_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("One simple duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {103, "A", {"T"}}) == 2 );
        }
        SECTION("One multiallelic duplicate") {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT", "C"}}) == 2 );
        }
        SECTION("Triplicate")
        {
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT", "C"}}) == 2 );
            // the first occurrence should not be reported again
            CHECK( count_duplicates_and_rethrow_error(cache, {100, "GA", {"GT"}}) == 1 );
        }
        SECTION("Symbolic Duplicates")
        {
            CHECK( count_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 0 );
            // This won't throw an error.
            CHECK( count_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 0 );
        }
    }

    TEST_CASE("Symbolic Duplicates test")
    {
        vcf::RecordCache cache{0};

        cache.check_duplicates(build_mock_record({100, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({101, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({102, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({103, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({104, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({105, "A", {"T"}}));
        cache.check_duplicates(build_mock_record({107, "C", {"<INS>"}}));

        SECTION("No symbolic duplicates") {
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {106, "A", {"T"}}) == 0 );
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {99, "GA", {"GT", "C"}}) == 0 );
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {103, "A", {"T"}}) == 0 );
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {100, "GA", {"GT", "C"}}) == 0 );
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {100, "GA", {"GT"}}) == 0 );
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {107, "C", {"<DEL>"}}) == 0 );
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {108, "C", {"<INS>"}}) == 0 );
        }

        SECTION("One Symbolic Duplicate")
        {
            // Symbolic duplicate detected
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 2 );
        }
        SECTION("Symbolic Triplicates")
        {
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 2 );
            // the first occurrence of symbolic duplicate should not be reported again
            CHECK( count_symbolic_duplicates_and_rethrow_error(cache, {107, "C", {"<INS>"}}) == 1 );
        }
    }
}
