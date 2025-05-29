Program Hello
    implicit none
    ! P = 5 x B - 400
    integer :: boilingTemp, kPa, KPA_AT_SEA_LEVEL = 100

    Read(*,*) boilingTemp
    kPa = 5 * boilingTemp - 400

    Print '(i0)', kPa
    if (kPa .GT. KPA_AT_SEA_LEVEL) then ! below sea level
        Print '(i0)', -1
    else if (kPa .LT. KPA_AT_SEA_LEVEL) then ! above sea level
        Print '(i0)', 1
    else ! at sea level
        Print '(i0)', 0
    end if
End Program Hello