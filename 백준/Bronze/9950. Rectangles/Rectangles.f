Program Hello
    integer :: length, width, area
    logical :: lengthMissing, widthMissing, areaMissing

    do
        Read(*, *) length, width, area
        lengthMissing = length .EQ. 0
        widthMissing = width .EQ. 0
        areaMissing = area .EQ. 0
        if (lengthMissing .and. widthMissing .and. areaMissing) then
            exit
        endif

        if (lengthMissing) then
            Print '(i0 a i0 a i0)', area/width, ' ', width, ' ', area
        elseif (widthMissing) then
            Print '(i0 a i0 a i0)', length, ' ', area/length, ' ', area
        else
            Print '(i0 a i0 a i0)', length, ' ', width, ' ', length*width
        endif
    end do
End Program Hello