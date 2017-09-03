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

#ifndef UTIL_LOGGER_HPP
#define UTIL_LOGGER_HPP

#include "boost/log/trivial.hpp"
#include "boost/log/expressions.hpp"
#include "boost/log/utility/setup/console.hpp"

namespace ebi
{
  namespace util
  {
    inline void init_boost_loggers()
    {
        boost::log::add_console_log
        (
            std::clog,
            boost::log::keywords::format =
            (
                boost::log::expressions::stream << "<" << boost::log::trivial::severity << "> " << boost::log::expressions::smessage
            )
        );
    }

    inline void logger_debug(std::string const & message)
    {
        init_boost_loggers();
        BOOST_LOG_TRIVIAL(debug) << message;
    }

    inline void logger_debug(std::string const & message, size_t line)
    {
        init_boost_loggers();
        BOOST_LOG_TRIVIAL(debug) << "Line " << std::to_string(line) << ": " << message;
    }

    inline void logger_info(std::string const & message)
    {
        init_boost_loggers();
        BOOST_LOG_TRIVIAL(info) << message;
    }

    inline void logger_warning(std::string const & message)
    {
        init_boost_loggers();
        BOOST_LOG_TRIVIAL(warning) << message;
    }

    inline void logger_warning(std::string const & message, size_t line)
    {
        init_boost_loggers();
        BOOST_LOG_TRIVIAL(warning) << "Line " << std::to_string(line) << ": " << message;
    }

    inline void logger_error(std::string const & message)
    {
        init_boost_loggers();
        BOOST_LOG_TRIVIAL(error) << message;
    }
  }
}

#endif // UTIL_LOGGER_HPP
