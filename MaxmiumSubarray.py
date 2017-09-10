# coding:utf8

# 最大子数组问题
INFINITY = 9999999

def FIND_MAX_CROSSING_SUBARRAY(a, low, mid, high):
	left_sum = -INFINITY
	sum = 0

	for i in range(low, mid + 1):
		sum += a[i]
		if sum > left_sum:
			left_sum = sum
			max_left = i

	right_sum = -INFINITY
	sum = 0

	for i in range(mid + 1, high + 1):
		sum += a[i]
		if sum > right_sum:
			right_sum = sum
			max_right = i

	return (max_left, max_right, left_sum + right_sum)

def FIND_MAXMIUM_SUBARRAY(a, low, high):
	if high == low:
		return (low, high, a[low])

	else:
		mid = (low + high) / 2
		(left_low, left_high, left_sum) = FIND_MAXMIUM_SUBARRAY(a, low, mid)
		(right_low, right_high, right_sum) = FIND_MAXMIUM_SUBARRAY(a, mid + 1, high)
		(cross_low, cross_high, cross_sum) = FIND_MAX_CROSSING_SUBARRAY(a, low, mid, high)

		if left_sum >= right_sum and left_sum >= cross_sum:
			return (left_low, left_high, left_sum)
		elif right_sum >= left_sum and right_sum >= cross_sum:
			return (right_low, right_high, right_sum)
		else:
			return (cross_low, cross_high, cross_sum)

a = [1, 4, 213, -12, 34, 987, 9, 97348797, 1234]
print(FIND_MAXMIUM_SUBARRAY(a, 0, len(a) - 1))