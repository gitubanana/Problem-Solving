Program Hello
    integer :: n, need, got, ans

    Read(*,*) n
    ans = 10**9
    do n=n,1,-1
        Read(*,*) need, got
        ans = min(ans, got / need)
    end do

    Print '(i0)', ans
End Program Hello