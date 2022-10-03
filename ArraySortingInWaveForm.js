// A JS program to sort an array in wave form using a sorting function
<script>
// A utility method to swap two numbers.
function swap(arr, x, y)
{
	let temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp
}

// This function sorts arr[0..n-1] in
// wave form, i.e., arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5]..
function sortInWave(arr, n)
{
	
	// Sort the input array
	arr.sort((a, b) => a - b);

	// Swap adjacent elements
	for(let i = 0; i < n - 1; i += 2)
		swap(arr, i, i + 1);
}

// Driver code
let arr = [ 10, 90, 49, 2, 1, 5, 23 ];
let n = arr.length;

sortInWave(arr, n);

for(let i = 0; i < n; i++)
	document.write(arr[i] + " ");

// Aryan Sahu

</script>
