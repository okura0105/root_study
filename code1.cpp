//ただplotするだけの最小機能のみのcode　(データはベタ打ち)

// メイン関数とファイル名は一致する必要がある
int code1(){
    //インタラクティブに打ち込んだ命令がリセットされるはず。なくてもいいはずだけど呪い的に打ってる
    gROOT -> Reset();

    
    const Int_t N = 6; //処理系に依存しない変数型
    int x[N] = {0,1,2,3,4,5};
    int y[N] = {0,1,4,9,16,25};

    /*
    rootが用意してるTGraphというclass
    TGraph(データの個数,x,y)
    第1引数はInt_t型じゃないとだめ
    */
    TGraph *g1 =new TGraph(N,x,y); //


    g1 ->Draw("AP"); //クラスのメソッドを使うことで物理解析機能を使う

    //ここは見やすさのために書いてるだけ。非本質
    g1 ->SetMarkerStyle(20);
    g1 ->SetMarkerSize(0.4);
    g1 ->SetMarkerColor(1);

    return 0;
}