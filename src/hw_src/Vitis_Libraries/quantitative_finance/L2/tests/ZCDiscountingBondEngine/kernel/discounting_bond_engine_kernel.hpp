/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _XF_FINTECH_BOND_KERNEL_HPP_
#define _XF_FINTECH_BOND_KERNEL_HPP_

#include "xf_fintech/discounting_bond_engine.hpp"

using namespace xf::fintech;
#define N 1
#define LEN 32

typedef double DT;

extern "C" void BOND_k0(int size, DT time[LEN], DT disc[LEN], DT amount, DT t, DT NPV[N]);

#endif
