temp  = 00000000 00000000 00000000 00000001 << 31
      = 10000000 00000000 00000000 00000000

// AND = &: Both 1 -> 1
65535 = 00000000 00000000 11111111 11111111
1     = 00000000 00000000 00000000 00000001
value = 00000000 00000000 00000000 00000001 = 1

// OR = |: At least 1 (>1) -> 1 (Sum)
15    = 00000000 00000000 00000000 00001111
241   = 00000000 00000000 00000000 11110001
value = 00000000 00000000 00000000 11111111 = 255

// exclusive OR = ^: Exactly 1 (=1) -> 1 (Minus)
139   = 00000000 00000000 00000000 10001011
199   = 00000000 00000000 00000000 11000111
value = 00000000 00000000 00000000 01001100