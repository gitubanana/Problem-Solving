Program Hello
    implicit none
    integer :: length, i
    integer :: bigData, security, ai, max_
    character(len=100001) :: likeList

    Read *, length
    Read *, likeList
    bigData = 0
    security = 0
    ai = 0
    do i=1,length
        select case (likeList(i:i))
            case ('B')
                bigData = bigData + 1
            case ('S')
                security = security + 1
            case ('A')
                ai = ai + 1
        end select
    end do

    if ((bigData .EQ. security) .and. (security .EQ. ai)) then
        Print '(a)', 'SCU'
        stop
    end if

    max_ = max(bigData, security, ai)
    if (max_ .EQ. bigData) then
        write(*, fmt="(a)", advance="no") 'B'
    end if

    if (max_ .EQ. security) then
        write(*, fmt="(a)", advance="no") 'S'
    end if

    if (max_ .EQ. ai) then
        write(*, fmt="(a)", advance="no") 'A'
    end if
End Program Hello