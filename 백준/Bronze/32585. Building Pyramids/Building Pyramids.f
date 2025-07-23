Program Hello
    implicit none
    integer(kind=8) :: n, ans

    Read(*, *) n
    ans = 0
    do n=n,1,-1
        ans = ans + n*(n+1)/2
    end do

    Print '(i0)', ans
End Program Hello