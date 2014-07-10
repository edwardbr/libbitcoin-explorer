/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RIPEMD160_HPP
#define RIPEMD160_HPP

#include <iostream>
#include <boost/program_options.hpp>
#include <bitcoin/bitcoin.hpp>
#include <sx/define.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace sx {
namespace serializer {

#define SX_SERIALIZER_RIPEMD160_EXCEPTION \
    "Invalid RIPEMD160 hash."

/**
 * Serialization helper to convert between hex string and short_hash.
 */
class ripemd160
{
public:

    /**
     * Constructor.
     */
    ripemd160()
        : value_() {}

    /**
     * Initialization constructor.
     * 
     * @param[in]  hex  The value to initialize with.
     */
    ripemd160(const std::string& hex)
    {
        std::stringstream(hex) >> *this;
    }

    /**
     * Initialization constructor.
     * 
     * @param[in]  hash  The value to initialize with.
     */
    ripemd160(const bc::short_hash& hash)
    {
        std::copy(hash.begin(), hash.end(), value_.begin());
    }

    /**
     * Initialization constructor.
     * 
     * @param[in]  address  The value to initialize with.
     */
    ripemd160(const bc::payment_address& address)
        : ripemd160(address.hash()) {}

    /**
     * Copy constructor.
     *
     * @param[in]  other  The object to copy into self on construct.
     */
    ripemd160(const ripemd160& other)
        : value_(other.value_) {}

    /**
     * Return a reference to the data member.
     *
     * @return  A reference to the object's internal data.
     */
    bc::short_hash& data()
    {
        return value_;
    }

    /**
     * Overload cast to internal type.
     *
     * @return  This object's value cast to internal type.
     */
    operator const bc::short_hash() const
    {
        return value_;
    }

    /**
     * Overload stream in. Throws if input is invalid.
     *
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    friend std::istream& operator>>(std::istream& input, ripemd160& argument)
    {
        std::string hex;
        input >> hex;
        auto hash = bc::decode_short_hash(hex);

        // TODO: determine how to properly raise error in deserialization.
        if (hash == bc::null_short_hash)
            throw po::invalid_option_value(SX_SERIALIZER_RIPEMD160_EXCEPTION);

        std::copy(hash.begin(), hash.end(), argument.value_.begin());
        return input;
    }

    /**
     * Overload stream out.
     *
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& output, 
        const ripemd160& argument)
    {
        output << bc::encode_hex(argument.value_);
        return output;
    }

private:

    /**
     * The state of this object.
     */
    bc::short_hash value_;
};

} // sx
} // serializer

#endif