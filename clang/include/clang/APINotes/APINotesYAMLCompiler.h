//===-- APINotesYAMLCompiler.h - API Notes YAML Format Reader ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_APINOTES_APINOTESYAMLCOMPILER_H
#define LLVM_CLANG_APINOTES_APINOTESYAMLCOMPILER_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/raw_ostream.h"

namespace clang {
namespace api_notes {
/// Parses the APINotes YAML content and writes the representation back to the
/// specified stream.  This provides a means of testing the YAML processing of
/// the APINotes format.
bool parseAndDumpAPINotes(llvm::StringRef YI, llvm::raw_ostream &OS);
} // namespace api_notes
} // namespace clang

#include "llvm/Support/SourceMgr.h"

namespace llvm {
class MemoryBuffer;
}

namespace clang {
class FileEntry;

namespace api_notes {
/// Converts API notes from YAML format to binary format.
bool compileAPINotes(llvm::StringRef yamlInput, const FileEntry *sourceFile,
                     llvm::raw_ostream &os,
                     llvm::SourceMgr::DiagHandlerTy diagHandler = nullptr,
                     void *diagHandlerCtxt = nullptr);
}
}

#endif
