# python3


def max_pairwise_product(numbers):
	n = len(numbers)
	maxindex1 = 0
	max1 = numbers[0]
	max2 = -100000
	
	l = len(numbers) #length of the Array
	for i in range(1,l):
		if numbers[i]>max1:
			max1 = numbers[i]
			maxindex1 = i
	for i in range(l):
		if numbers[i]>max2 and i!=maxindex1:
			max2 = numbers[i]
			
		#print(max1,max2)

	return max1 * max2


if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))
