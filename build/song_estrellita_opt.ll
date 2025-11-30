; ModuleID = 'AudioScoreModule'
source_filename = "AudioScoreModule"

@wavName = private unnamed_addr constant [11 x i8] c"output.wav\00", align 1

declare void @init_wav_writer(ptr) local_unnamed_addr

declare void @finalize_wav() local_unnamed_addr

declare void @write_sine_note(double, i32) local_unnamed_addr

define noundef i32 @main() local_unnamed_addr {
entry:
  tail call void @init_wav_writer(ptr nonnull @wavName)
  tail call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  tail call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 4.400000e+02, i32 600)
  tail call void @write_sine_note(double 4.400000e+02, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 1200)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  tail call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  tail call void @write_sine_note(double 0x40705A0250C2B956, i32 1200)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 1200)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 1200)
  tail call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  tail call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  tail call void @write_sine_note(double 4.400000e+02, i32 600)
  tail call void @write_sine_note(double 4.400000e+02, i32 600)
  tail call void @write_sine_note(double 0x40787FED4E47ADFF, i32 1200)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  tail call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  tail call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  tail call void @write_sine_note(double 0x40705A0250C2B956, i32 1200)
  tail call void @finalize_wav()
  ret i32 0
}
