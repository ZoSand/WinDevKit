#pragma once

#include <cassert>

#define WDK_ASSERT(conditions, message) assert(conditions && message);
