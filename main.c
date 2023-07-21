#include <stdlib.h>
#include <stdio.h>

int	merge_sort(int *sorted, int *array, int start, int end);
int	ft_arrprint(int *a, int n);
int	copy(int *dst, int *src, int start, int end);

int	main(void)
{
	int	a[] = {0, -4, 2, 3, 5, 1, 9, 8};
	int	*b;

	b = (int *)malloc(sizeof(int) * 8);
	ft_arrprint(a, 8);
	merge_sort(b, a, 0, 8);
	ft_arrprint(a, 8);
	return (0);
}

int	merge(int *sorted, int *array, int start, int end)
{
	int	mid;
	int	i;
	int	j;
	int	k;

	mid = (end - start) / 2;
	i = start;
	j = mid;
	k = start;
	while (i < mid && j < end)
	{
		if (array[i] < array[j])
			sorted[k++] = array[i++];
		else
			sorted[k++] = array[j++];
	}
	while (i < mid)
		sorted[k++] = array[i++];
	while (j < end)
		sorted[k++] = array[j++];
	copy(array, sorted, start, end); 
	return (0);
}

int	merge_sort(int *sorted, int *array, int start, int end)
{
	int	mid;

	mid = 1 + (end - start) / 2;
	if (end - start > 2)
	{
		merge_sort(sorted, array, mid, end);
		merge_sort(sorted, array, start, mid);
		merge(sorted, array, start, end);
	}
	return (0);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	copy(int *dst, int *src, int start, int end)
{
	int	i;
	int	n;

	n = end - start;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (0);
}

int	ft_arrprint(int *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d\n", a[i]);
		i++;
	}
	return (0);
}
