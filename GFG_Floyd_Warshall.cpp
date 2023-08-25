class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int nodes = matrix.size();
	    
	    // creating adjacancy matrix:
	    for(int i=0; i<nodes; i++)
	    {
	        for(int j=0; j<nodes; j++)
	        {
	            // not reachable:
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	            
	            // same node distance is zero:
	            if(i == j) matrix[i][j] = 0;
	        }
	    }
	    
	    // floyd warshall apply:
	    for(int via=0; via<nodes; via++)
	    {
	        for(int i=0; i<nodes; i++)
	        {
	            for(int j=0; j<nodes; j++)
	            {
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    // again making INT_Max to -1 wherever it is:
	    for(int i=0; i<nodes; i++)
	    {
	        for(int j=0; j<nodes; j++)
	        {
	            // not reachable:
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }
	}
};