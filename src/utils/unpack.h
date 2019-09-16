/*******************************************************************************
*   Ark Wallet
*   (c) 2017 Ledger
*   (c) ARK Ecosystem
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#ifndef ARK_UTILS_UNPACK_H
#define ARK_UTILS_UNPACK_H

#include <os.h>

////////////////////////////////////////////////////////////////////////////////

#define U8BE(buf, off)  (((uint64_t)(U4BE(buf, off)                     & 0xFFFFFFFF) << 32U)   |   \
                        ((uint64_t)(U4BE(buf, off + sizeof(uint32_t)))  & 0xFFFFFFFF))

#define U8LE(buf, off)  (((uint64_t)(U4LE(buf, off))                    & 0xFFFFFFFF)           |   \
                        ((uint64_t)(U4LE(buf, off + sizeof(uint32_t))  & 0xFFFFFFFF) << 32U))

////////////////////////////////////////////////////////////////////////////////

#endif
