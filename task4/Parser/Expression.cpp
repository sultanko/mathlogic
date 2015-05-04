#include "Expression.h"

size_t Expression::getHash() const
{
    return hash_string;
}

const char *ExpressionException::what() const _GLIBCXX_USE_NOEXCEPT
{
    return message.c_str();
}
