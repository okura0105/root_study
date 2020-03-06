//code3.cppがrichになっただけ

int code4(){
    gROOT -> Reset();
    gStyle->SetOptFit(1);

    int i=0;
    float x,y,y_error;

    FILE *fp;
    fp = fopen("./data2.csv","r");

    TGraphErrors *g1 =new TGraphErrors();
    TF1 *f1 = new TF1("fitting","[0]*x^2+[1]*x+[2]");


    //whileでやると、csvの行数がわかってなくても大丈夫
    while(fscanf(fp,"%f,%f,%f",&x,&y,&y_error)!=EOF){
        g1 ->SetPoint(i,x,y);
        g1 ->SetPointError(i,0,y_error);
        i++;
    }

    fclose(fp);

    f1 -> SetLineColor(4);//fitting線の色変更
    f1 -> FixParameter(0,1); //パラメタをfixできる。FixParameter(パラメタ番号,固定数値)
    f1 -> SetParLimits(1,0.2,0.4);//パラメタをfixできる。SetParLimits(パラメタ番号,下限,上限)
    f1 -> SetParName(2,"offset");//パラメタの名前を決めれる。

    g1 ->Fit("fitting","","",0,5);

    g1 ->SetMarkerStyle(20);
    g1 ->SetMarkerSize(0.4);
    g1 ->SetMarkerColor(1);

    g1 ->Draw("AP");

    return 0;
}