// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>

#include "testing/embedder_test.h"
#include "testing/gtest/include/gtest/gtest.h"

class FXCodecEmbeddertest : public EmbedderTest {};

TEST_F(FXCodecEmbeddertest, Bug_631912) {
  // Test jbig2 image in PDF file can be loaded successfully.
  // Should not crash.
  EXPECT_TRUE(OpenDocument("bug_631912.pdf"));
  FPDF_PAGE page = LoadPage(0);
  ASSERT_TRUE(page);
  std::unique_ptr<void, FPDFBitmapDeleter> bitmap = RenderLoadedPage(page);
  CompareBitmap(bitmap.get(), 691, 432, "24d75af646f8772c5ee7ced260452ae4");
  UnloadPage(page);
}
