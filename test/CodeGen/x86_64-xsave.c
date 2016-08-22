// RUN: %clang_cc1 %s -DTEST_XSAVE -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVE
// RUN: %clang_cc1 %s -DTEST_XSAVE -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVE

// RUN: %clang_cc1 %s -DTEST_XSAVEOPT -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -target-feature +xsaveopt -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVEOPT
// RUN: %clang_cc1 %s -DTEST_XSAVEOPT -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -target-feature +xsaveopt -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVEOPT

// RUN: %clang_cc1 %s -DTEST_XSAVEC -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -target-feature +xsavec -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVEC
// RUN: %clang_cc1 %s -DTEST_XSAVEC -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -target-feature +xsavec -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVEC

// RUN: %clang_cc1 %s -DTEST_XSAVES -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -target-feature +xsaves -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVES
// RUN: %clang_cc1 %s -DTEST_XSAVES -O0 -triple=x86_64-unknown-unknown -target-feature +xsave -target-feature +xsaves -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s --check-prefix=XSAVES

void test() {
  unsigned long long tmp_ULLi = 0;
  void*              tmp_vp = 0;

#ifdef TEST_XSAVE
// XSAVE: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVE: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVE: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
// XSAVE: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
// XSAVE: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
// XSAVE: call void @llvm.x86.xsave(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
  (void)__builtin_ia32_xsave(tmp_vp, tmp_ULLi);

// XSAVE: [[tmp_vp_2:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVE: [[tmp_ULLi_2:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVE: [[high64_2:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_2]], 32
// XSAVE: [[high32_2:%[0-9a-zA-z]+]] = trunc i64 [[high64_2]] to i32
// XSAVE: [[low32_2:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_2]] to i32
// XSAVE: call void @llvm.x86.xsave64(i8* [[tmp_vp_2]], i32 [[high32_2]], i32 [[low32_2]])
  (void)__builtin_ia32_xsave64(tmp_vp, tmp_ULLi);

// XSAVE: [[tmp_vp_3:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVE: [[tmp_ULLi_3:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVE: [[high64_3:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_3]], 32
// XSAVE: [[high32_3:%[0-9a-zA-z]+]] = trunc i64 [[high64_3]] to i32
// XSAVE: [[low32_3:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_3]] to i32
// XSAVE: call void @llvm.x86.xrstor(i8* [[tmp_vp_3]], i32 [[high32_3]], i32 [[low32_3]])
  (void)__builtin_ia32_xrstor(tmp_vp, tmp_ULLi);

// XSAVE: [[tmp_vp_4:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVE: [[tmp_ULLi_4:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVE: [[high64_4:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_4]], 32
// XSAVE: [[high32_4:%[0-9a-zA-z]+]] = trunc i64 [[high64_4]] to i32
// XSAVE: [[low32_4:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_4]] to i32
// XSAVE: call void @llvm.x86.xrstor64(i8* [[tmp_vp_4]], i32 [[high32_4]], i32 [[low32_4]])
  (void)__builtin_ia32_xrstor64(tmp_vp, tmp_ULLi);
#endif

#ifdef TEST_XSAVEOPT
// XSAVEOPT: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVEOPT: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVEOPT: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
// XSAVEOPT: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
// XSAVEOPT: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
// XSAVEOPT: call void @llvm.x86.xsaveopt(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
  (void)__builtin_ia32_xsaveopt(tmp_vp, tmp_ULLi);

// XSAVEOPT: [[tmp_vp_2:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVEOPT: [[tmp_ULLi_2:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVEOPT: [[high64_2:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_2]], 32
// XSAVEOPT: [[high32_2:%[0-9a-zA-z]+]] = trunc i64 [[high64_2]] to i32
// XSAVEOPT: [[low32_2:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_2]] to i32
// XSAVEOPT: call void @llvm.x86.xsaveopt64(i8* [[tmp_vp_2]], i32 [[high32_2]], i32 [[low32_2]])
  (void)__builtin_ia32_xsaveopt64(tmp_vp, tmp_ULLi);
#endif

#ifdef TEST_XSAVEC
// XSAVEC: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVEC: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVEC: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
// XSAVEC: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
// XSAVEC: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
// XSAVEC: call void @llvm.x86.xsavec(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
  (void)__builtin_ia32_xsavec(tmp_vp, tmp_ULLi);

// XSAVEC: [[tmp_vp_2:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVEC: [[tmp_ULLi_2:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVEC: [[high64_2:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_2]], 32
// XSAVEC: [[high32_2:%[0-9a-zA-z]+]] = trunc i64 [[high64_2]] to i32
// XSAVEC: [[low32_2:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_2]] to i32
// XSAVEC: call void @llvm.x86.xsavec64(i8* [[tmp_vp_2]], i32 [[high32_2]], i32 [[low32_2]])
  (void)__builtin_ia32_xsavec64(tmp_vp, tmp_ULLi);
#endif

#ifdef TEST_XSAVES
// XSAVES: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVES: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVES: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
// XSAVES: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
// XSAVES: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
// XSAVES: call void @llvm.x86.xsaves(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
  (void)__builtin_ia32_xsaves(tmp_vp, tmp_ULLi);

// XSAVES: [[tmp_vp_2:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVES: [[tmp_ULLi_2:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVES: [[high64_2:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_2]], 32
// XSAVES: [[high32_2:%[0-9a-zA-z]+]] = trunc i64 [[high64_2]] to i32
// XSAVES: [[low32_2:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_2]] to i32
// XSAVES: call void @llvm.x86.xsaves64(i8* [[tmp_vp_2]], i32 [[high32_2]], i32 [[low32_2]])
  (void)__builtin_ia32_xsaves64(tmp_vp, tmp_ULLi);

// XSAVES: [[tmp_vp_3:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVES: [[tmp_ULLi_3:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVES: [[high64_3:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_3]], 32
// XSAVES: [[high32_3:%[0-9a-zA-z]+]] = trunc i64 [[high64_3]] to i32
// XSAVES: [[low32_3:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_3]] to i32
// XSAVES: call void @llvm.x86.xrstors(i8* [[tmp_vp_3]], i32 [[high32_3]], i32 [[low32_3]])
  (void)__builtin_ia32_xrstors(tmp_vp, tmp_ULLi);

// XSAVES: [[tmp_vp_4:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 8
// XSAVES: [[tmp_ULLi_4:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
// XSAVES: [[high64_4:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_4]], 32
// XSAVES: [[high32_4:%[0-9a-zA-z]+]] = trunc i64 [[high64_4]] to i32
// XSAVES: [[low32_4:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_4]] to i32
// XSAVES: call void @llvm.x86.xrstors64(i8* [[tmp_vp_4]], i32 [[high32_4]], i32 [[low32_4]])
  (void)__builtin_ia32_xrstors64(tmp_vp, tmp_ULLi);
#endif
}
