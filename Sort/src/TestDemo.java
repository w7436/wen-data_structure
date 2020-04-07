import java.util.Stack;

/**
 * @ClassName TestDemo
 * @Description TODO
 * @Author DELL
 * @Data 2020/4/7 11:52
 * @Version 1.0
 **/

public class TestDemo {
    public static void insertSort(int nums[]){
        for(int i = 1; i < nums.length;i++) {
            int end = i - 1;
            int key = nums[i];

            while (end >= 0 && key < nums[end]) {
                nums[end + 1] = nums[end];
                end--;
            }
            nums[end + 1] = key;
        }
    }

    //(O(n^1.25)~O(1.6n^1.25)) kunth
    public static void shellSort(int nums[]){
        int gap = nums.length;
        while(gap > 1){
            gap = gap/3+1;
            for(int i = gap; i < nums.length;i++) {
                int end = i - gap;
                int key = nums[i];

                while (end >= 0 && key < nums[end]) {
                    nums[end + gap] = nums[end];
                    end-=gap;
                }
                nums[end + gap] = key;
            }
            gap--;
        }
    }

    public static void selectSort(int[] nums){
        for(int i = 0;i < nums.length-1;i++){
            int maxPos = 0;
            for(int j = 1; j < nums.length-i; j++){
                if(nums[j] > nums[maxPos]){
                    maxPos = j;
                }
            }
            if(maxPos!=nums.length-1-i){
                swap(nums,maxPos,nums.length-1-i);
            }

        }
    }
    public static void selectSortOP(int[] nums){
        int begin = 0,end = nums.length-1;
        while(begin < end){
            int maxPos = begin;
            int minPos = begin;
            int index = begin+1;
            while(index <= end){
                if(nums[index] > nums[maxPos]){
                    maxPos = index;
                }
                if(nums[index] < nums[minPos]){
                    minPos = index;
                }
                index++;
            }
            if(maxPos!=end){
                swap(nums,maxPos,end);
            }
            if(minPos == end){
                minPos = maxPos;
            }
            if(minPos !=begin){
                swap(nums,minPos,begin);
            }
            begin++;
            end--;
        }
    }

    public static void HeapSort(int[] array){
        //找倒数第一个非叶子结点
        int lastroot = (array.length-2)>>1;

        //从lastroot到root的位置不断进行向下调整
        for (int root = lastroot ; root  >= 0 ; root--) {
            shifDown(array,root,array.length);
        }
        //堆删除
        int end = array.length-1;
        while(end >= 0){
            swap(array,0,end);
            shifDown(array,0,end);
            end--;
        }
    }

//向下调整
    private static void shifDown(int[] array, int parent,int size) {
        int child = parent*2+1;
        while(child <size){
            //找左右孩子中较大的孩子
            if(child+1 < size && array[child+1] > array[child])
                child+=1;
            //检测双亲是否比较大的孩子小

            if(array[child] >array[parent]){
                swap(array,child,parent);
                parent = child;
                child = parent*2+1;
            }
            else{
                break;
            }
        }
    }

    public static void quickSort(int[] array,int left,int right){
        if(right  - left >1){
            int div = partion1(array,left,right);
            quickSort(array,left,div);
            quickSort(array,div+1,right);
        }
    }

    private static int partion2(int[] array, int left, int right){
         int cur = left;
         int prev = cur-1;
         int key = array[right-1];
         while(cur < right){
             if(array[cur] < key && ++prev != cur)
                 swap(array,cur,prev);
             ++cur;
         }
         if(++prev != right-1){
             swap(array,prev,right-1);
         }
         return prev;
    }
    private static int partion(int[] array, int left, int right) {

        int begin = 0;
        int end = right -1;
        int key = array[end];
        while(begin < end){
            while(begin < end &&array [begin] <= key){
                begin++;
            }
            while(begin < end && array[end] >= key){
                end--;
            }
            if(begin < end){
                swap(array,begin,end);
            }
        }
        if(begin != right -1)
            swap(array,begin,right-1);
        return begin;


    }
    //挖坑法
    private static int partion1(int[] array, int left, int right) {
        int begin = left;
        int end = right-1;
        int key = array[end];
        while(begin < end){
            //
            while (begin < end &&array[begin] <= key){
                begin++;
            }
            //找到一个比基准值大的元素
            if(begin  < end){
                array[end--] = array[begin];
            }
            while(begin < end&&array[end] >= key){
                end--;
            }
            //找到一个比基准值小的元素
            if(begin < end){
                array[begin--]=array[end];
            }
        }
        array[begin] =key;
        return begin;
    }

    public static void quickSortNor(int[] array){
        Stack<Integer> a = new Stack<>();
        a.push(array.length);
        a.push(0);
        while(!a.empty()){
            int left = a.pop();
            int right = a.pop();
            if(right - left  > 1){
                int div = partion(array,left,right);

            }
        }
    }

    public static void mergeData(int[] array,int left,int mid,int right,int[] tmp){
        int index = left;
        int begin1 = left;
        int end1 = mid;
        int begin2 = mid;
        int end2 = right;
        while(begin1 <end1 && begin2 < end2){
            if(array[begin1] <= array[begin2]){
                tmp[index++] = array[begin1++];
            }
            else{
                tmp[index++] = array[begin2];
            }
        }
        while(begin1 < end1){
            tmp[index ++] = array[begin1++];
        }
        while(begin2 < end2){
            tmp[index++] = array[begin2++];
        }

    }
    public static void mergeSort(int[] array,int left,int right,int[] tmp){
        if(right - left >1){
            int mid= left +((right-left)>>1);
            mergeSort(array,left,mid,tmp);
            mergeSort(array,mid,right,tmp);
            //归并
            mergeData(array,left,mid,right,tmp);
            //归并结束，有序序列存贮在tmp中
            System.arraycopy(tmp,left,array,left,right-left);
        }
    }
    public static void mergeSort1(int[] array){
        int[] tmp = new int[array.length];
        int gap = 1;
        while(gap < array.length){
            for (int i = 0; i < array.length ; i+=gap*2) {
                int left = i;
                int mid = left +gap;
                int right = mid+gap;
                if(mid >array.length){
                    mid = array.length;
                }
                if(right > array.length){
                    right = array.length;
                }
                mergeData(array,left,mid,right,tmp);

            }
            System.arraycopy(tmp,0,array,0,array.length);
            gap*=2;
        }
    }
    public static void swap(int[] arr,int l,int r){
        int tmp = arr[l];
        arr[l] =arr[r];
        arr[r] = tmp;
    }
    public static void printArray(int[] nums){
        for(int e:nums){
            System.out.print(e+" ");
        }
    }
    public static void main(String[] args) {
        int[] nums = {2,5,1,5,3,7,9};
//        insertSort(nums);
//        shellSort(nums);
//        selectSort(nums);
//        selectSortOP(nums);
//        HeapSort(nums);
        quickSort(nums,0,7);
        printArray(nums);

    }
}
