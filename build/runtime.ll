; ModuleID = '../runtime/runtime_audio_wav.c'
source_filename = "../runtime/runtime_audio_wav.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [5 x i8] c"RIFF\00", align 1
@.str.1 = private unnamed_addr constant [5 x i8] c"WAVE\00", align 1
@.str.2 = private unnamed_addr constant [5 x i8] c"fmt \00", align 1
@.str.3 = private unnamed_addr constant [5 x i8] c"data\00", align 1
@.str.4 = private unnamed_addr constant [11 x i8] c"output.wav\00", align 1
@.str.5 = private unnamed_addr constant [3 x i8] c"wb\00", align 1
@wavFile = internal unnamed_addr global ptr null, align 8
@stderr = external local_unnamed_addr global ptr, align 8
@.str.6 = private unnamed_addr constant [50 x i8] c"[runtime] ERROR: no se pudo abrir output.wav: %s\0A\00", align 1
@totalSamples = internal unnamed_addr global i32 0, align 4
@stdout = external local_unnamed_addr global ptr, align 8
@.str.8 = private unnamed_addr constant [40 x i8] c"[runtime] Write note %.2f Hz for %d ms\0A\00", align 1
@.str.9 = private unnamed_addr constant [45 x i8] c"[runtime] ERROR: wavFile NULL en write_rest\0A\00", align 1
@.str.10 = private unnamed_addr constant [26 x i8] c"[runtime] REST for %d ms\0A\00", align 1
@.str.11 = private unnamed_addr constant [47 x i8] c"[runtime] ERROR: wavFile NULL en finalize_wav\0A\00", align 1
@str = private unnamed_addr constant [33 x i8] c"[runtime] WAV writer initialized\00", align 1
@str.14 = private unnamed_addr constant [33 x i8] c"[runtime] Finalizing WAV file...\00", align 1
@str.15 = private unnamed_addr constant [34 x i8] c"[runtime] WAV saved as output.wav\00", align 1

; Function Attrs: nofree nounwind sspstrong uwtable
define dso_local void @write_little_endian_4(ptr noundef captures(none) %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = alloca [4 x i8], align 1
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %3) #9
  %4 = trunc i32 %1 to i8
  store i8 %4, ptr %3, align 1, !tbaa !5
  %5 = lshr i32 %1, 8
  %6 = trunc i32 %5 to i8
  %7 = getelementptr inbounds nuw i8, ptr %3, i64 1
  store i8 %6, ptr %7, align 1, !tbaa !5
  %8 = lshr i32 %1, 16
  %9 = trunc i32 %8 to i8
  %10 = getelementptr inbounds nuw i8, ptr %3, i64 2
  store i8 %9, ptr %10, align 1, !tbaa !5
  %11 = lshr i32 %1, 24
  %12 = trunc nuw i32 %11 to i8
  %13 = getelementptr inbounds nuw i8, ptr %3, i64 3
  store i8 %12, ptr %13, align 1, !tbaa !5
  %14 = call i64 @fwrite(ptr noundef nonnull %3, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %3) #9
  ret void
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr captures(none)) #1

; Function Attrs: nofree nounwind
declare noundef i64 @fwrite(ptr noundef readonly captures(none), i64 noundef, i64 noundef, ptr noundef captures(none)) local_unnamed_addr #2

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr captures(none)) #1

; Function Attrs: nofree nounwind sspstrong uwtable
define dso_local void @write_little_endian_2(ptr noundef captures(none) %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = alloca [2 x i8], align 1
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %3) #9
  %4 = trunc i32 %1 to i8
  store i8 %4, ptr %3, align 1, !tbaa !5
  %5 = lshr i32 %1, 8
  %6 = trunc i32 %5 to i8
  %7 = getelementptr inbounds nuw i8, ptr %3, i64 1
  store i8 %6, ptr %7, align 1, !tbaa !5
  %8 = call i64 @fwrite(ptr noundef nonnull %3, i64 noundef 1, i64 noundef 2, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %3) #9
  ret void
}

; Function Attrs: nofree nounwind sspstrong uwtable
define dso_local void @write_wav_header_empty(ptr noundef captures(none) %0) local_unnamed_addr #0 {
  %2 = alloca [4 x i8], align 4
  %3 = alloca [2 x i8], align 1
  %4 = alloca [2 x i8], align 1
  %5 = alloca [4 x i8], align 4
  %6 = alloca [4 x i8], align 4
  %7 = alloca [2 x i8], align 1
  %8 = alloca [2 x i8], align 1
  %9 = alloca [4 x i8], align 4
  %10 = alloca [4 x i8], align 4
  %11 = tail call i64 @fwrite(ptr noundef nonnull @.str, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %10) #9
  store i32 0, ptr %10, align 4
  %12 = call i64 @fwrite(ptr noundef nonnull %10, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %10) #9
  %13 = tail call i64 @fwrite(ptr noundef nonnull @.str.1, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  %14 = tail call i64 @fwrite(ptr noundef nonnull @.str.2, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %9) #9
  store <4 x i8> <i8 16, i8 0, i8 0, i8 0>, ptr %9, align 4, !tbaa !5
  %15 = call i64 @fwrite(ptr noundef nonnull %9, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %9) #9
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %8) #9
  store i8 1, ptr %8, align 1, !tbaa !5
  %16 = getelementptr inbounds nuw i8, ptr %8, i64 1
  store i8 0, ptr %16, align 1, !tbaa !5
  %17 = call i64 @fwrite(ptr noundef nonnull %8, i64 noundef 1, i64 noundef 2, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %8) #9
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %7) #9
  store i8 1, ptr %7, align 1, !tbaa !5
  %18 = getelementptr inbounds nuw i8, ptr %7, i64 1
  store i8 0, ptr %18, align 1, !tbaa !5
  %19 = call i64 @fwrite(ptr noundef nonnull %7, i64 noundef 1, i64 noundef 2, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %7) #9
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %6) #9
  store <4 x i8> <i8 68, i8 -84, i8 0, i8 0>, ptr %6, align 4, !tbaa !5
  %20 = call i64 @fwrite(ptr noundef nonnull %6, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %6) #9
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %5) #9
  store <4 x i8> <i8 -120, i8 88, i8 1, i8 0>, ptr %5, align 4, !tbaa !5
  %21 = call i64 @fwrite(ptr noundef nonnull %5, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %5) #9
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %4) #9
  store i8 2, ptr %4, align 1, !tbaa !5
  %22 = getelementptr inbounds nuw i8, ptr %4, i64 1
  store i8 0, ptr %22, align 1, !tbaa !5
  %23 = call i64 @fwrite(ptr noundef nonnull %4, i64 noundef 1, i64 noundef 2, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %4) #9
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %3) #9
  store i8 16, ptr %3, align 1, !tbaa !5
  %24 = getelementptr inbounds nuw i8, ptr %3, i64 1
  store i8 0, ptr %24, align 1, !tbaa !5
  %25 = call i64 @fwrite(ptr noundef nonnull %3, i64 noundef 1, i64 noundef 2, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %3) #9
  %26 = tail call i64 @fwrite(ptr noundef nonnull @.str.3, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %2) #9
  store i32 0, ptr %2, align 4
  %27 = call i64 @fwrite(ptr noundef nonnull %2, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %2) #9
  ret void
}

; Function Attrs: nofree nounwind sspstrong uwtable
define dso_local void @fix_wav_header_sizes(ptr noundef captures(none) %0) local_unnamed_addr #0 {
  %2 = alloca [4 x i8], align 1
  %3 = alloca [4 x i8], align 1
  %4 = tail call i64 @ftell(ptr noundef %0)
  %5 = trunc i64 %4 to i32
  %6 = add nsw i32 %5, -44
  %7 = tail call i32 @fseek(ptr noundef %0, i64 noundef 4, i32 noundef 0)
  %8 = add nsw i32 %5, -8
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %3) #9
  %9 = trunc i32 %8 to i8
  store i8 %9, ptr %3, align 1, !tbaa !5
  %10 = lshr i32 %8, 8
  %11 = trunc i32 %10 to i8
  %12 = getelementptr inbounds nuw i8, ptr %3, i64 1
  store i8 %11, ptr %12, align 1, !tbaa !5
  %13 = lshr i32 %8, 16
  %14 = trunc i32 %13 to i8
  %15 = getelementptr inbounds nuw i8, ptr %3, i64 2
  store i8 %14, ptr %15, align 1, !tbaa !5
  %16 = lshr i32 %8, 24
  %17 = trunc nuw i32 %16 to i8
  %18 = getelementptr inbounds nuw i8, ptr %3, i64 3
  store i8 %17, ptr %18, align 1, !tbaa !5
  %19 = call i64 @fwrite(ptr noundef nonnull %3, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %3) #9
  %20 = tail call i32 @fseek(ptr noundef %0, i64 noundef 40, i32 noundef 0)
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %2) #9
  %21 = trunc i32 %6 to i8
  store i8 %21, ptr %2, align 1, !tbaa !5
  %22 = lshr i32 %6, 8
  %23 = trunc i32 %22 to i8
  %24 = getelementptr inbounds nuw i8, ptr %2, i64 1
  store i8 %23, ptr %24, align 1, !tbaa !5
  %25 = lshr i32 %6, 16
  %26 = trunc i32 %25 to i8
  %27 = getelementptr inbounds nuw i8, ptr %2, i64 2
  store i8 %26, ptr %27, align 1, !tbaa !5
  %28 = lshr i32 %6, 24
  %29 = trunc nuw i32 %28 to i8
  %30 = getelementptr inbounds nuw i8, ptr %2, i64 3
  store i8 %29, ptr %30, align 1, !tbaa !5
  %31 = call i64 @fwrite(ptr noundef nonnull %2, i64 noundef 1, i64 noundef 4, ptr noundef %0)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %2) #9
  ret void
}

; Function Attrs: nofree nounwind
declare noundef i64 @ftell(ptr noundef captures(none)) local_unnamed_addr #2

; Function Attrs: nofree nounwind
declare noundef i32 @fseek(ptr noundef captures(none), i64 noundef, i32 noundef) local_unnamed_addr #2

; Function Attrs: nounwind sspstrong uwtable
define dso_local void @init_wav_writer() local_unnamed_addr #3 {
  %1 = tail call noalias ptr @fopen(ptr noundef nonnull @.str.4, ptr noundef nonnull @.str.5)
  store ptr %1, ptr @wavFile, align 8, !tbaa !8
  %2 = icmp eq ptr %1, null
  br i1 %2, label %3, label %9

3:                                                ; preds = %0
  %4 = load ptr, ptr @stderr, align 8, !tbaa !8
  %5 = tail call ptr @__errno_location() #10
  %6 = load i32, ptr %5, align 4, !tbaa !11
  %7 = tail call ptr @strerror(i32 noundef %6) #9
  %8 = tail call i32 (ptr, ptr, ...) @fprintf(ptr noundef %4, ptr noundef nonnull @.str.6, ptr noundef %7) #11
  br label %11

9:                                                ; preds = %0
  tail call void @write_wav_header_empty(ptr noundef nonnull %1)
  store i32 0, ptr @totalSamples, align 4, !tbaa !11
  %10 = tail call i32 @puts(ptr nonnull dereferenceable(1) @str)
  br label %11

11:                                               ; preds = %9, %3
  %12 = phi ptr [ @stdout, %9 ], [ @stderr, %3 ]
  %13 = load ptr, ptr %12, align 8, !tbaa !8
  %14 = tail call i32 @fflush(ptr noundef %13)
  ret void
}

; Function Attrs: nofree nounwind
declare noalias noundef ptr @fopen(ptr noundef readonly captures(none), ptr noundef readonly captures(none)) local_unnamed_addr #2

; Function Attrs: nofree nounwind
declare noundef i32 @fprintf(ptr noundef captures(none), ptr noundef readonly captures(none), ...) local_unnamed_addr #2

; Function Attrs: nounwind
declare ptr @strerror(i32 noundef) local_unnamed_addr #4

; Function Attrs: mustprogress nofree nosync nounwind willreturn memory(none)
declare ptr @__errno_location() local_unnamed_addr #5

; Function Attrs: nofree nounwind
declare noundef i32 @fflush(ptr noundef captures(none)) local_unnamed_addr #2

; Function Attrs: nofree nounwind
declare noundef i32 @printf(ptr noundef readonly captures(none), ...) local_unnamed_addr #2

; Function Attrs: nofree nounwind sspstrong uwtable
define dso_local void @write_sine_note(double noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = alloca i16, align 2
  %4 = mul nsw i32 %1, 44100
  %5 = sdiv i32 %4, 1000
  %6 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str.8, double noundef %0, i32 noundef %1)
  %7 = icmp sgt i32 %1, 0
  br i1 %7, label %8, label %11

8:                                                ; preds = %2
  %9 = fmul double %0, 0x401921FB54442D18
  %10 = tail call i32 @llvm.smax.i32(i32 %5, i32 1)
  br label %14

11:                                               ; preds = %14, %2
  %12 = load i32, ptr @totalSamples, align 4, !tbaa !11
  %13 = add nsw i32 %12, %5
  store i32 %13, ptr @totalSamples, align 4, !tbaa !11
  ret void

14:                                               ; preds = %8, %14
  %15 = phi i32 [ 0, %8 ], [ %24, %14 ]
  %16 = uitofp nneg i32 %15 to double
  %17 = fdiv double %16, 4.410000e+04
  %18 = fmul double %9, %17
  %19 = tail call double @sin(double noundef %18) #9, !tbaa !11
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %3) #9
  %20 = fmul double %19, 3.276700e+04
  %21 = fptosi double %20 to i16
  store i16 %21, ptr %3, align 2, !tbaa !13
  %22 = load ptr, ptr @wavFile, align 8, !tbaa !8
  %23 = call i64 @fwrite(ptr noundef nonnull %3, i64 noundef 2, i64 noundef 1, ptr noundef %22)
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %3) #9
  %24 = add nuw nsw i32 %15, 1
  %25 = icmp eq i32 %24, %10
  br i1 %25, label %11, label %14, !llvm.loop !15
}

; Function Attrs: mustprogress nocallback nofree nounwind willreturn memory(errnomem: write)
declare double @sin(double noundef) local_unnamed_addr #6

; Function Attrs: nofree nounwind sspstrong uwtable
define dso_local void @write_rest(i32 noundef %0) local_unnamed_addr #0 {
  %2 = alloca i16, align 2
  %3 = load ptr, ptr @wavFile, align 8, !tbaa !8
  %4 = icmp eq ptr %3, null
  br i1 %4, label %5, label %10

5:                                                ; preds = %1
  %6 = load ptr, ptr @stderr, align 8, !tbaa !8
  %7 = tail call i64 @fwrite(ptr nonnull @.str.9, i64 44, i64 1, ptr %6) #12
  %8 = load ptr, ptr @stderr, align 8, !tbaa !8
  %9 = tail call i32 @fflush(ptr noundef %8)
  br label %28

10:                                               ; preds = %1
  %11 = mul nsw i32 %0, 44100
  %12 = sdiv i32 %11, 1000
  %13 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str.10, i32 noundef %0)
  %14 = load ptr, ptr @stdout, align 8, !tbaa !8
  %15 = tail call i32 @fflush(ptr noundef %14)
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %2) #9
  store i16 0, ptr %2, align 2, !tbaa !13
  %16 = icmp sgt i32 %0, 0
  br i1 %16, label %17, label %19

17:                                               ; preds = %10
  %18 = tail call i32 @llvm.smax.i32(i32 %12, i32 1)
  br label %22

19:                                               ; preds = %22, %10
  %20 = load i32, ptr @totalSamples, align 4, !tbaa !11
  %21 = add nsw i32 %20, %12
  store i32 %21, ptr @totalSamples, align 4, !tbaa !11
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %2) #9
  br label %28

22:                                               ; preds = %17, %22
  %23 = phi i32 [ %26, %22 ], [ 0, %17 ]
  %24 = load ptr, ptr @wavFile, align 8, !tbaa !8
  %25 = call i64 @fwrite(ptr noundef nonnull %2, i64 noundef 2, i64 noundef 1, ptr noundef %24)
  %26 = add nuw nsw i32 %23, 1
  %27 = icmp eq i32 %26, %18
  br i1 %27, label %19, label %22, !llvm.loop !17

28:                                               ; preds = %19, %5
  ret void
}

; Function Attrs: nofree nounwind sspstrong uwtable
define dso_local void @finalize_wav() local_unnamed_addr #0 {
  %1 = alloca [4 x i8], align 1
  %2 = alloca [4 x i8], align 1
  %3 = load ptr, ptr @wavFile, align 8, !tbaa !8
  %4 = icmp eq ptr %3, null
  br i1 %4, label %5, label %8

5:                                                ; preds = %0
  %6 = load ptr, ptr @stderr, align 8, !tbaa !8
  %7 = tail call i64 @fwrite(ptr nonnull @.str.11, i64 46, i64 1, ptr %6) #12
  br label %44

8:                                                ; preds = %0
  %9 = tail call i32 @puts(ptr nonnull dereferenceable(1) @str.14)
  %10 = load ptr, ptr @stdout, align 8, !tbaa !8
  %11 = tail call i32 @fflush(ptr noundef %10)
  %12 = load ptr, ptr @wavFile, align 8, !tbaa !8
  %13 = tail call i64 @ftell(ptr noundef %12)
  %14 = trunc i64 %13 to i32
  %15 = add nsw i32 %14, -44
  %16 = tail call i32 @fseek(ptr noundef %12, i64 noundef 4, i32 noundef 0)
  %17 = add nsw i32 %14, -8
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %2) #9
  %18 = trunc i32 %17 to i8
  store i8 %18, ptr %2, align 1, !tbaa !5
  %19 = lshr i32 %17, 8
  %20 = trunc i32 %19 to i8
  %21 = getelementptr inbounds nuw i8, ptr %2, i64 1
  store i8 %20, ptr %21, align 1, !tbaa !5
  %22 = lshr i32 %17, 16
  %23 = trunc i32 %22 to i8
  %24 = getelementptr inbounds nuw i8, ptr %2, i64 2
  store i8 %23, ptr %24, align 1, !tbaa !5
  %25 = lshr i32 %17, 24
  %26 = trunc nuw i32 %25 to i8
  %27 = getelementptr inbounds nuw i8, ptr %2, i64 3
  store i8 %26, ptr %27, align 1, !tbaa !5
  %28 = call i64 @fwrite(ptr noundef nonnull %2, i64 noundef 1, i64 noundef 4, ptr noundef %12)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %2) #9
  %29 = tail call i32 @fseek(ptr noundef %12, i64 noundef 40, i32 noundef 0)
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %1) #9
  %30 = trunc i32 %15 to i8
  store i8 %30, ptr %1, align 1, !tbaa !5
  %31 = lshr i32 %15, 8
  %32 = trunc i32 %31 to i8
  %33 = getelementptr inbounds nuw i8, ptr %1, i64 1
  store i8 %32, ptr %33, align 1, !tbaa !5
  %34 = lshr i32 %15, 16
  %35 = trunc i32 %34 to i8
  %36 = getelementptr inbounds nuw i8, ptr %1, i64 2
  store i8 %35, ptr %36, align 1, !tbaa !5
  %37 = lshr i32 %15, 24
  %38 = trunc nuw i32 %37 to i8
  %39 = getelementptr inbounds nuw i8, ptr %1, i64 3
  store i8 %38, ptr %39, align 1, !tbaa !5
  %40 = call i64 @fwrite(ptr noundef nonnull %1, i64 noundef 1, i64 noundef 4, ptr noundef %12)
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %1) #9
  %41 = load ptr, ptr @wavFile, align 8, !tbaa !8
  %42 = tail call i32 @fclose(ptr noundef %41)
  store ptr null, ptr @wavFile, align 8, !tbaa !8
  %43 = tail call i32 @puts(ptr nonnull dereferenceable(1) @str.15)
  br label %44

44:                                               ; preds = %8, %5
  %45 = phi ptr [ @stdout, %8 ], [ @stderr, %5 ]
  %46 = load ptr, ptr %45, align 8, !tbaa !8
  %47 = tail call i32 @fflush(ptr noundef %46)
  ret void
}

; Function Attrs: nofree nounwind
declare noundef i32 @fclose(ptr noundef captures(none)) local_unnamed_addr #2

; Function Attrs: nofree nounwind
declare noundef i32 @puts(ptr noundef readonly captures(none)) local_unnamed_addr #7

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i32 @llvm.smax.i32(i32, i32) #8

attributes #0 = { nofree nounwind sspstrong uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #2 = { nofree nounwind "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind sspstrong uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { mustprogress nofree nosync nounwind willreturn memory(none) "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { mustprogress nocallback nofree nounwind willreturn memory(errnomem: write) "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { nofree nounwind }
attributes #8 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #9 = { nounwind }
attributes #10 = { nounwind willreturn memory(none) }
attributes #11 = { cold nounwind }
attributes #12 = { cold }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"clang version 21.1.5"}
!5 = !{!6, !6, i64 0}
!6 = !{!"omnipotent char", !7, i64 0}
!7 = !{!"Simple C/C++ TBAA"}
!8 = !{!9, !9, i64 0}
!9 = !{!"p1 _ZTS8_IO_FILE", !10, i64 0}
!10 = !{!"any pointer", !6, i64 0}
!11 = !{!12, !12, i64 0}
!12 = !{!"int", !6, i64 0}
!13 = !{!14, !14, i64 0}
!14 = !{!"short", !6, i64 0}
!15 = distinct !{!15, !16}
!16 = !{!"llvm.loop.mustprogress"}
!17 = distinct !{!17, !16}
