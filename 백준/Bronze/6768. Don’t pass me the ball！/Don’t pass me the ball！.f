Program Hello
    Read(*,*) n
    if (n .LT. 4) then
        Print '(i0)', 0
    else
        Print '(i0)', (n-1) * (n-2) * (n-3) / 6
    end if
End Program Hello
