// -*- Mode: c++; c-basic-offset: 4; tab-width: 4; -*-

/******************************************************************************
 *
 *  file:  ArgTraits.h
 *
 *
 *****************************************************************************/

// This is an internal tclap file, you should probably not have to
// include this directly

#ifndef TCLAP_ARGTRAITS_H
#define TCLAP_ARGTRAITS_H

namespace TCLAP {

// We use two empty structs to get compile type specialization
// function to work

/**
 * A value like argument value type is a value that can be set using
 * operator>>. This is the default value type.
 */
struct ValueLike {
    typedef ValueLike ValueCategory;
};

/**
 * A string like argument value type is a value that can be set using
 * operator=(string). Usefull if the value type contains spaces which
 * will be broken up into individual tokens by operator>>.
 */
struct StringLike {};

/**
 * A class can inherit from this object to make it have string like
 * traits. This is a compile time thing and does not add any overhead
 * to the inherenting class.
 */
struct StringLikeTrait {
    typedef StringLike ValueCategory;
};

/**
 * A class can inherit from this object to make it have value like
 * traits. This is a compile time thing and does not add any overhead
 * to the inherenting class.
 */
struct ValueLikeTrait {
    typedef ValueLike ValueCategory;
};

/**
 * Arg traits are used to get compile type specialization when parsing
 * argument values. Using an ArgTraits you can specify the way that
 * values gets assigned to any particular type during parsing. The two
 * supported types are string like and value like.
 */
template<typename T>
struct ArgTraits {
    typedef typename T::ValueCategory ValueCategory;
    //typedef ValueLike ValueCategory;
};

#endif

} // namespace