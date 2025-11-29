; ModuleID = 'AudioScoreModule'
source_filename = "AudioScoreModule"

declare void @init_wav_writer()

declare void @finalize_wav()

declare void @write_sine_note(double, i32)

declare void @write_rest(i32)

define i32 @main() {
entry:
  call void @init_wav_writer()
  call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 4.400000e+02, i32 600)
  call void @write_sine_note(double 4.400000e+02, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 1200)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  call void @write_sine_note(double 0x40705A0250C2B956, i32 1200)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 1200)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 1200)
  call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  call void @write_sine_note(double 0x40705A0250C2B956, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 600)
  call void @write_sine_note(double 4.400000e+02, i32 600)
  call void @write_sine_note(double 4.400000e+02, i32 600)
  call void @write_sine_note(double 0x40787FED4E47ADFF, i32 1200)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x4075D3A6D600CABC, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40749A0A791E127B, i32 600)
  call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  call void @write_sine_note(double 0x40725AA2E3AF0B21, i32 600)
  call void @write_sine_note(double 0x40705A0250C2B956, i32 1200)
  call void @finalize_wav()
  ret i32 0
}
