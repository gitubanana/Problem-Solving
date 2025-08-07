Program Hello
    implicit none
    integer :: goal
    integer :: watt, volt

    Read(*, *) goal
    Read(*, *) watt, volt

    if (watt / volt .GE. goal) then
        Print '(a)', '1'
    else
        Print '(a)', '0'
    endif
End Program Hello