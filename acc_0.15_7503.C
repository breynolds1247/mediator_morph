void acc_0.15_7503()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 12 18:15:33 2017) by ROOT version6.10/08
   TCanvas *c1 = new TCanvas("c1", "c1",10,44,700,500);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-0.5,-0.11375,4.5,1.12375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *frame__13 = new TH2D("frame__13","",10,0,4,10,0.01,1);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("frame");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean x =      0");
   ptstats_LaTex = ptstats->AddText("Mean y =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev x =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(11111);
   ptstats->Draw();
   frame__13->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__13);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__13->SetLineColor(ci);
   frame__13->GetXaxis()->SetLabelFont(42);
   frame__13->GetXaxis()->SetLabelSize(0.035);
   frame__13->GetXaxis()->SetTitleSize(0.035);
   frame__13->GetXaxis()->SetTitleFont(42);
   frame__13->GetYaxis()->SetLabelFont(42);
   frame__13->GetYaxis()->SetLabelSize(0.035);
   frame__13->GetYaxis()->SetTitleSize(0.035);
   frame__13->GetYaxis()->SetTitleOffset(0);
   frame__13->GetYaxis()->SetTitleFont(42);
   frame__13->GetZaxis()->SetLabelFont(42);
   frame__13->GetZaxis()->SetLabelSize(0.035);
   frame__13->GetZaxis()->SetTitleSize(0.035);
   frame__13->GetZaxis()->SetTitleFont(42);
   frame__13->Draw("");
   
   Double_t _fx25[11] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   0.35,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy25[11] = {
   0.225,
   0.239,
   0.144,
   0.207,
   0.243,
   0.008,
   0.246,
   0.241,
   0.244,
   0.242,
   0.242};
   TGraph *graph = new TGraph(11,_fx25,_fy25);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph25 = new TH1F("Graph_Graph25","",100,0.185,2.165);
   Graph_Graph25->SetMinimum(0.0072);
   Graph_Graph25->SetMaximum(0.2698);
   Graph_Graph25->SetDirectory(0);
   Graph_Graph25->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph25->SetLineColor(ci);
   Graph_Graph25->GetXaxis()->SetLabelFont(42);
   Graph_Graph25->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph25->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph25->GetXaxis()->SetTitleFont(42);
   Graph_Graph25->GetYaxis()->SetLabelFont(42);
   Graph_Graph25->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph25->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph25->GetYaxis()->SetTitleOffset(0);
   Graph_Graph25->GetYaxis()->SetTitleFont(42);
   Graph_Graph25->GetZaxis()->SetLabelFont(42);
   Graph_Graph25->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph25->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph25->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph25);
   
   
   TF1 *mp26 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp26->SetFillColor(19);
   mp26->SetFillStyle(0);
   mp26->SetLineColor(2);
   mp26->SetLineWidth(2);
   mp26->SetChisquare(7.650038e-05);
   mp26->SetNDF(5);
   mp26->GetXaxis()->SetLabelFont(42);
   mp26->GetXaxis()->SetLabelSize(0.035);
   mp26->GetXaxis()->SetTitleSize(0.035);
   mp26->GetXaxis()->SetTitleFont(42);
   mp26->GetYaxis()->SetLabelFont(42);
   mp26->GetYaxis()->SetLabelSize(0.035);
   mp26->GetYaxis()->SetTitleSize(0.035);
   mp26->GetYaxis()->SetTitleOffset(0);
   mp26->GetYaxis()->SetTitleFont(42);
   mp26->SetParameter(0,0.09977343);
   mp26->SetParError(0,0.0002468975);
   mp26->SetParLimits(0,0,0.1);
   mp26->SetParameter(1,0.4185807);
   mp26->SetParError(1,0.006992939);
   mp26->SetParLimits(1,0,2);
   mp26->SetParameter(2,13.25809);
   mp26->SetParError(2,0.3549076);
   mp26->SetParLimits(2,0.1,100);
   mp26->SetParameter(3,-12.29562);
   mp26->SetParError(3,3.007706);
   mp26->SetParLimits(3,0,0);
   mp26->SetParameter(4,-0.02651702);
   mp26->SetParError(4,0.005711832);
   mp26->SetParLimits(4,0,0);
   graph->GetListOfFunctions()->Add(mp26);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
