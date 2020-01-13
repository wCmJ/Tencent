namespace GRAPH{
		typedef enum{UNDISCOVERED, DISCOVERED, VISITED}VStatus;
		template<typename Tv>
		struct Vertex{
				Tv data;
				int inDegree, outDegree;
				VStatus status;
				int dTime, fTime;//discover time, access time
				int parent;
				int priority;
				Vertex(Tv const &d):data(d),inDegree(0),outDegree(0),status(UNDISCOVERED),dTime(-1),fTime(-1),parent(-1),priority(INT_MAX){}
		};

    typedef enum{UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD}EStatus;
    template<typename Te>
    struct Edge{
				Te data;
				int weight;
				EStatus status;
				Edge(Te const &d, int w):data(d),weight(w),status(UNDISCOVERED){}
    };


    template<typename Tv, typename Te>
    class Graph{
      //first, how to display a graph
      //
    private:
				void reset()
				{
					for(int i=0;i<n;i++)
					{
						status(i) = UNDISCOVERED;
						dTime(i) = fTime(i) = -1;
						parent(i) = -1;
						priority(i) = INT_MAX;
						for(int j=0;j<n;++j)
						{
							if(exist(i,j))
								status(i,j) = UNDETERMINED;
						}
					}
				}

    public:
    //for vertex, edge, algorithm

    };
    template<typename Tv, typename Te>
    class GraphMatrix: public Graph<Tv, Te>
    {
    private:
				std::vector< Vertex<Tv>> v;//n
				std::vector< std::vector< Edge<Te>*>> E;//邻接矩阵

    public:
				GraphMatrix(){n = e = 0;}
				~GraphMatrix()
				{
					for(int i=0;i<n;++i)
						for(int j=0;j<n;++j)
							delete E[i][j];
				}

				//i-> |0|1|0|0|1|...|j(<-)|
				int nextNbr(int i, int j)//已枚举至邻居j,则转向下一个邻居
				{
					while((-1 < j) && (!exist(i, --j)));//逆向顺序查找
					return j;
				}
				int firstNbr(int i){
					return nextNbr(i, n);
				}
				bool exist(int i, int j){
					return (0 <= i) && (i < n) && (0 <= j) && (j < n) && (E[i][j] != NULL);
				}

				//insert edge
				void insert(Te const &edge, int w, int i, int j)
				{
					if(exist(i,j))return;//ignore exist edge
					E[i][j] = new Edge(edge, w);
					e++;
					v[i].outDegree++;
					v[j].inDegree++;
				}


				Tv& vertex(int i){return v[i].data;}
				int inDegree(int i){return v[i].inDegree;}
				int outDegree(int i){return v[i].outDegree;}
				VStatus status(int i){return v[i].status;}
				int& dTime(int i){return v[i].dTime;}
				int& fTime(int i){return v[i].fTime;}
				int& parent(int i){return v[i].parent;}
				int& priority(int i){return v[i].priority;}

    };

}
