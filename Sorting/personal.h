void display(int arr[], int n) {
	printf("array is \n");

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}

	std::cout << std::endl;
}


void input(int arr[], int n) {

	printf("enter elements: ");

	for (int i = 0; i < n; ++i)
	{
		
		std::cin>>arr[i];

	}
}

void input(int b, int arr[], int n) {
	printf("enter elements: ");
	for (int i = 0; i < n; ++i)
	{
		
		arr[i] = rand() % 50;

		printf("%d ", arr[i]);

	}

	std::cout << std::endl;
}

void bubbSort(int arr[], int n) {
	int i, j;

	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*void input2x2(int arr[][3])
{
	printf("\n enter elements of array \n");

	for (int i = 0; i < 2; ++i)
	{


		for (int j = 0; j < 3; ++j)
		{
			int a = rand()%10000;
			arr[i][j] = a;
			printf("%d\t", arr[i][j]);
		}

		cout<<endl;
	}
}*/



