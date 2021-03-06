/*******************************************************************************
 * This file is part of the ARK Ledger App.
 *
 * Copyright (c) ARK Ecosystem <info@ark.io>
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#ifndef ARK_OPERATIONS_MESSAGE_H
#define ARK_OPERATIONS_MESSAGE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "constants.h"

#include "utils/hex.h"
#include "utils/print.h"
#include "utils/utils.h"

#include "display/context.h"
#include "display/display.h"

////////////////////////////////////////////////////////////////////////////////

extern void setDisplaySteps(uint8_t steps, bool isExtended);

////////////////////////////////////////////////////////////////////////////////
// Prepare a Message Operation for Display.
//
// - UTF8 Encoded
// - 255 Byte Max
//
// ---
bool handleMessage(const uint8_t *buffer, size_t length) {
    if (length == 0 || length > MAX_TEXT_LEN) {
        return false;
    }

    explicit_bzero(&displayCtx, sizeof(displayCtx));

    const char *const LABEL     = "Message";
    const size_t LABEL_SIZE     = 8;

    const char *const LABEL_LENGTH      = "length:";
    const size_t LABEL_LENGTH_SIZE      = 8;

    const size_t MESSAGE_DISPLAY_STEPS = 2;

    bytecpy((char *)displayCtx.operation, LABEL, LABEL_SIZE);
    bytecpy((char *)displayCtx.title[0], LABEL_LENGTH, LABEL_LENGTH_SIZE);
    bytecpy((char *)displayCtx.extended_title, LABEL, LABEL_SIZE);

    // Message Length
    printAmount(length,
                displayCtx.text[0],
                sizeof(displayCtx.text[0]),
                "", 0U, 0U);

    // Message Text
    bytecpy((char *)displayCtx.extended_text, buffer, length);

    setDisplaySteps(MESSAGE_DISPLAY_STEPS, true);

    return true;
}

#endif  // #define ARK_OPERATIONS_MESSAGE_H
