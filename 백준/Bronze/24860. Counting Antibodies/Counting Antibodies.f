Program Hello
    implicit none
    integer(kind=8) :: vk, jk
    integer(kind=8) :: vl, jl
    integer(kind=8) :: vh, dh, jh
    integer(kind=8) :: heavyCnt

    Read *, vk, jk
    Read *, vl, jl
    Read *, vh, dh, jh

    heavyCnt = vh * dh * jh
    Print '(i0)', vk * jk * heavyCnt + vl * jl * heavyCnt
End Program Hello