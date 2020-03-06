//csvからデータを読んで誤差付きでplot、fittingするコード
//data2.csvは   x,y,y_error　の形式

int code3(){
    gROOT -> Reset();
    gStyle->SetOptFit(1);//fitting結果を見るために書く

    float x,y,y_error;

    FILE *fp;
    fp = fopen("./data2.csv","r");

    TGraphErrors *g1 =new TGraphErrors();
    TF1 *f1 = new TF1("fitting","[0]*x^2+[1]*x+[2]");//fitting関数を定義。TF1("名前","関数の形")。[0]とかはパラメタ


    for(int i=0;i<6;i++){
        fscanf(fp,"%f,%f,%f",&x,&y,&y_error);
        g1 ->SetPoint(i,x,y);
        g1 ->SetPointError(i,0,y_error);//SetPointError(index番号,x誤差,y誤差)
    }
    fclose(fp);

    g1 ->Fit("fitting","","",0,6);//Fit("fitting関数の名前","","",fit範囲,fit範囲);

    g1 ->SetMarkerStyle(20);
    g1 ->SetMarkerSize(0.4);
    g1 ->SetMarkerColor(1);

    g1 ->Draw("AP");

    return 0;
}