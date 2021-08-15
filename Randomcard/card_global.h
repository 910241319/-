#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CARD_LIB)
#  define CARD_EXPORT Q_DECL_EXPORT
# else
#  define CARD_EXPORT Q_DECL_IMPORT
# endif
#else
# define CARD_EXPORT
#endif
