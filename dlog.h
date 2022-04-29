// Copyright (C) <2019> Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0
#pragma once

#include <cstdio>
#include <string>

extern std::string DGetLogHeader();

#define DLOG(format, args...)                                            \
  do {                                                                   \
    printf("%s[%s:%d] - " format, DGetLogHeader().c_str(), __FUNCTION__, \
           __LINE__, ##args);                                            \
  } while (0)
