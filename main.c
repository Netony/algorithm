#include <stdlib.h>
#include <stdio.h>

int	merge_sort(int *sorted, int *array, int start, int end);
int	ft_arrprint(int *a, int start, int end);
int	copy(int *dst, int *src, int start, int end);
int	*parse(int argc, char **argv);

int	main(int argc, char **argv)
{
	int	*array;
	int	*buf;

	array = parse(argc, argv);
	if (array == NULL)
		return (0);
	buf = (int *)malloc(sizeof(int) * (argc - 1));
	ft_arrprint(array, 0, argc - 1);
	merge_sort(buf, array, 0, argc - 1);
	free(buf);
	ft_arrprint(array, 0, argc - 1);
	free(array);
	return (0);
}

int	*parse(int argc, char **argv)
{
	int	*array;
	int	i;

	if (argc < 2)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (argc - 1));
	argv++;
	i = 0;
	while (i < argc - 1)
		array[i++] = atoi(*(argv++));
	return (array);
}

int	merge(int *sorted, int *array, int start, int end)
{
	int	mid;
	int	i;
	int	j;
	int	k;

	mid = (end + start) / 2;
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
	while (start < end)
	{
		array[start] = sorted[start];
		start++;
	}
	return (0);
}

int	merge_sort(int *sorted, int *array, int start, int end)
{
	int	mid;

	if (end - start > 1)
	{
		mid = (end + start) / 2;
		merge_sort(sorted, array, mid, end);
		merge_sort(sorted, array, start, mid);
		merge(sorted, array, start, end);
	}
	return (0);
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

int	ft_arrprint(int *a, int start, int end)
{
	while (start < end)
		printf("%d\n", a[start++]);
	return (0);
}
