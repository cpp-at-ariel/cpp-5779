#!python3
#
# The Computer Language Benchmarks Game
# https://salsa.debian.org/benchmarksgame-team/benchmarksgame/
#
# contributed by Joerg Baumann

"""
NOTES:
64-bit Ubuntu quad core
Python 3.7.3


Thu, 09 May 2019 19:03:40 GMT

MAKE:
mv mandelbrot.python3-7.python3 mandelbrot.python3-7.py
pytype .
make: pytype: Command not found
make: [/home/dunham/8000-benchmarksgame/nanobench/makefiles/u64q.programs.Makefile:514: mandelbrot.python3-7.python3_run] Error 127 (ignored)

0.35s to complete and log all make actions

COMMAND LINE:
/opt/src/Python-3.7.3/bin/python3 -OO mandelbrot.python3-7.py 16000

(BINARY) PROGRAM OUTPUT NOT SHOWN
"""


from contextlib import closing
from itertools import islice
from os import cpu_count
from sys import argv, stdout

def pixels(y, n, abs):
	range7 = bytearray(range(7))
	print(range7)
	pixel_bits = bytearray(128 >> pos for pos in range(8))
	print(pixel_bits)
	c1 = 2. / float(n)
	c0 = -1.5 + 1j * y * c1 - 1j
	x = 0
	while True:
		pixel = 0
		c = x * c1 + c0
		for pixel_bit in pixel_bits:
			z = c
			for _ in range7:
				for _ in range7:
					z = z * z + c
				if abs(z) >= 2.: break
			else:
				pixel += pixel_bit
			c += c1
		yield pixel
		x += 8

def compute_row(p):
	y, n = p
	pxls = pixels(y, n, abs)
	result = bytearray(islice(pxls, (n + 7) // 8))
	result[-1] &= 0xff << (8 - n % 8)
	return y, result

def mandelbrot(n):
	write = stdout.buffer.write
	
	row_jobs = ((y, n) for y in range(n))
	rows = map(compute_row, row_jobs) 
	write("P4\n{0} {0}\n".format(n).encode())
	for row in rows:
		write(row[1])

if __name__ == '__main__':
	# mandelbrot(int(argv[1]))
	mandelbrot(16000)

	