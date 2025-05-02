# [Silver III] CIDR - 24743 

[문제 링크](https://www.acmicpc.net/problem/24743) 

### 성능 요약

메모리: 1432 KB, 시간: 24 ms

### 분류

비트마스킹, 수학

### 제출 일자

2025년 5월 2일 09:17:45

### 문제 설명

<p>Internet Protocol (IP) V4 addresses are 32-bit integers that uniquely identify a host on the internet. IP addresses are written in a dotted-quad notation such as 192.168.1.100. Each component of the dotted-quad specifies an 8-bit (unsigned) value, corresponding to each of the 4 bytes in the 32-bit integer address. An IP address specifies two groups of bits in that 32-bit integer: the network group and the host group. The least significant bits in the address specify the specific host on the network described by the most significant bits.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/db000669-5197-4a83-8e15-68d80c01a3c2/-/preview/" style="width: 728px; height: 68px;"></p>

<p>The network mask is a bitmask that has all the bits in the network group set to 1. Ex. If the network group has 14 bits, then the netmask is: <code>0xfffc0000</code> or, in dotted-quad format: <code>255.252.0.0</code></p>

<p>Historically, each group consisted of a multiple of 8 bits: 8, 16 or 24. This led to problems with IP address allocation: the total number of networks were usually too big or too small for most organizations to use. The smallest number of hosts on a network was 256 (8 bits of host). This turns out to be a waste of IP address space, since rarely did small networks need  256 hosts.</p>

<p>The Classless Inter-Domain Routing (CIDR) was introduced to deal with this. It allows for any number of bits to be used for the network and host groups, as long as the total bits used by the network and host groups totals 32. CIDR notation specifies a dotted-quad IP Address, a slash (‘/’) character, and a decimal number (0-32). For example, <code>192.168.1.100/14</code> represents the IP address <code>192.168.1.100</code> and its associated network prefix of 192.128.0.0, or equivalently a netmask of <code>255.252.0.0</code> which has 14 leading 1-bits.</p>

<p>For this problem, you will write a program that accepts a list of dotted-quad IP V4 addresses and determines the network group that contains all the specified IP addresses with the smallest number of unused or wasted hosts.</p>

### 입력 

 <p>The first line of input contains a single decimal integer N, (2 ≤ N ≤ 65535), which is the number of dotted-quad IP addresses the follow. This is followed by N lines, each containing a valid dotted-quad IP address.</p>

### 출력 

 <p>The single output line consists of a single integer value representing the number of bits in the network group. That is, the integer value that follows the slash, (‘/’), character in the CIDR representation of an address in the network group. If there is no common network group shared by the IP addresses, you should print 32, this is a special case which is commonly used to refer to specific hosts, that is, there is no network component. This implies you should never output a value of 0.</p>

