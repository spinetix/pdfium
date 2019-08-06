// Copyright 2019 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FPDFSDK_PWL_IPWL_SYSTEMHANDLER_H_
#define FPDFSDK_PWL_IPWL_SYSTEMHANDLER_H_

#include "core/fxcrt/fx_coordinates.h"
#include "core/fxcrt/fx_system.h"
#include "core/fxcrt/timerhandler_iface.h"

class CPDFSDK_Widget;
class CFFL_FormFiller;

class IPWL_SystemHandler : public TimerHandlerIface {
 public:
  ~IPWL_SystemHandler() override = default;

  virtual void InvalidateRect(CPDFSDK_Widget* widget,
                              const CFX_FloatRect& rect) = 0;
  virtual void OutputSelectedRect(CFFL_FormFiller* pFormFiller,
                                  const CFX_FloatRect& rect) = 0;
  virtual bool IsSelectionImplemented() const = 0;
  virtual void SetCursor(int32_t nCursorType) = 0;
};

#endif  // FPDFSDK_PWL_IPWL_SYSTEMHANDLER_H_