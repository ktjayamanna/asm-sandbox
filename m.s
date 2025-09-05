_initialize:
    addi s1, zero, 2
    addi s3, zero, 5


_add_two_five_times:
    add s2, s1, s2
    addi s3, s3, -1
    bnez s3, _add_two_five_times
