//csvからデータを読んでplotするコード
//やってることはcode1.cppと一緒

int code2(){
    gROOT -> Reset();

    int x,y;

    FILE *fp;
    fp = fopen("./data1.csv","r");

    TGraph *g1 =new TGraph();//データを全く入れないでTGraphのインスタンスを生成

    for(int i=0;i<6;i++){
        fscanf(fp,"%d,%d",&x,&y);//1列目をx,2列目をyで受け取ってる
        g1 ->SetPoint(i,x,y);//SetPointは第一引数にInt_tじゃなく、データのindexを入れる
    }
    fclose(fp);



    g1 ->SetMarkerStyle(20);
    g1 ->SetMarkerSize(0.4);
    g1 ->SetMarkerColor(1);

    g1 ->Draw("AP");

    return 0;
}