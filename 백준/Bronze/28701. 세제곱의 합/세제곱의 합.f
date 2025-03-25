Program Hello
    implicit none
    integer :: i, n, sum_, cubeSum

    sum_ = 0
    cubeSum = 0
    Read *, n
    do i = 1, n
        sum_ = sum_ + i
        cubeSum = cubeSum + i**3
    end do

    Print '(I0)', sum_
    Print '(I0)', sum_**2
    Print '(I0)', cubeSum
End Program Hello