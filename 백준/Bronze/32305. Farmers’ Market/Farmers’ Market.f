Program Hello
    integer :: numberOfApplesInBag
    integer :: numberOfBags
    integer :: dozenPrice

    Read(*, *) numberOfApplesInBag, numberOfBags, dozenPrice
    Print '(i0)', (numberOfApplesInBag * numberOfBags + 11) / 12 * dozenPrice
End Program Hello