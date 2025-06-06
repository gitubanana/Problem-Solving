Program Hello
    integer :: numberOfApplesInBag
    integer :: numberOfBags
    integer :: dozenCnt, dozenPrice

    Read(*, *) numberOfApplesInBag, numberOfBags, dozenPrice

    dozenCnt = numberOfApplesInBag * numberOfBags / 12;
    if (dozenCnt * 12 .NE. numberOfApplesInBag * numberOfBags) then
        dozenCnt = dozenCnt + 1
    endif

    Print '(i0)', dozenCnt * dozenPrice
End Program Hello