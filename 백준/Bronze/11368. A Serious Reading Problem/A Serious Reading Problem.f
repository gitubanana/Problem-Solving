Program Hello
    do
        Read(*, *) i, j, k, l
        if (isEnd(i, j, k, l)) then
            stop
        endif

        ! ** 연산자 우결합(right-assciative)
        Print '(i0)', ((i**j)**k)**l
    end do
contains
    function isEnd(i, j, k, l) result(itIs)
        logical :: itIs

        itIs = (i .EQ. 0) .AND. (j .EQ. 0) .AND. (k .EQ. 0) .AND. (l .EQ. 0)
    end function
End Program Hello