// Copyright (C) <2019> Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>

#include <iostream>

#include <sys/syscall.h>
#include <unistd.h>
#define gettid() syscall(SYS_gettid)

static std::string NowString(void) {
  auto now = std::chrono::system_clock::now();
  auto t_c = std::chrono::system_clock::to_time_t(now);
  uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                    now.time_since_epoch())
                    .count();

  std::stringstream dateStream;
  dateStream << std::put_time(std::localtime(&t_c), "%T") << "." << ms % 1000;
  return dateStream.str();
}

std::string DGetLogHeader() {
  std::stringstream header;
  header << "[t" << gettid() << "]"
         << "[" << NowString() << "]";
  return header.str();
}
