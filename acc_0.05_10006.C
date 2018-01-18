void acc_0.05_10006()
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
   
   TH2D *frame__9 = new TH2D("frame__9","",10,0,4,10,0.01,1);
   
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
   frame__9->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__9);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__9->SetLineColor(ci);
   frame__9->GetXaxis()->SetLabelFont(42);
   frame__9->GetXaxis()->SetLabelSize(0.035);
   frame__9->GetXaxis()->SetTitleSize(0.035);
   frame__9->GetXaxis()->SetTitleFont(42);
   frame__9->GetYaxis()->SetLabelFont(42);
   frame__9->GetYaxis()->SetLabelSize(0.035);
   frame__9->GetYaxis()->SetTitleSize(0.035);
   frame__9->GetYaxis()->SetTitleOffset(0);
   frame__9->GetYaxis()->SetTitleFont(42);
   frame__9->GetZaxis()->SetLabelFont(42);
   frame__9->GetZaxis()->SetLabelSize(0.035);
   frame__9->GetZaxis()->SetTitleSize(0.035);
   frame__9->GetZaxis()->SetTitleFont(42);
   frame__9->Draw("");
   
   Double_t _fx17[6] = {
   0.65,
   0.75,
   0.85,
   0.95,
   0.45,
   0.55};
   Double_t _fy17[6] = {
   0.341,
   0.405,
   0.433,
   0.448,
   0.01,
   0.154};
   TGraph *graph = new TGraph(6,_fx17,_fy17);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph17 = new TH1F("Graph_Graph17","",100,0.4,1);
   Graph_Graph17->SetMinimum(0.009);
   Graph_Graph17->SetMaximum(0.4918);
   Graph_Graph17->SetDirectory(0);
   Graph_Graph17->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph17->SetLineColor(ci);
   Graph_Graph17->GetXaxis()->SetLabelFont(42);
   Graph_Graph17->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph17->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph17->GetXaxis()->SetTitleFont(42);
   Graph_Graph17->GetYaxis()->SetLabelFont(42);
   Graph_Graph17->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph17->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph17->GetYaxis()->SetTitleOffset(0);
   Graph_Graph17->GetYaxis()->SetTitleFont(42);
   Graph_Graph17->GetZaxis()->SetLabelFont(42);
   Graph_Graph17->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph17->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph17);
   
   
   TF1 *mp18 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp18->SetFillColor(19);
   mp18->SetFillStyle(0);
   mp18->SetLineColor(2);
   mp18->SetLineWidth(2);
   mp18->SetChisquare(0.000779189);
   mp18->SetNDF(1);
   mp18->GetXaxis()->SetLabelFont(42);
   mp18->GetXaxis()->SetLabelSize(0.035);
   mp18->GetXaxis()->SetTitleSize(0.035);
   mp18->GetXaxis()->SetTitleFont(42);
   mp18->GetYaxis()->SetLabelFont(42);
   mp18->GetYaxis()->SetLabelSize(0.035);
   mp18->GetYaxis()->SetTitleSize(0.035);
   mp18->GetYaxis()->SetTitleOffset(0);
   mp18->GetYaxis()->SetTitleFont(42);
   mp18->SetParameter(0,0.4349898);
   mp18->SetParError(0,0.01503255);
   mp18->SetParLimits(0,0,0);
   mp18->SetParameter(1,0.5843257);
   mp18->SetParError(1,0.01188643);
   mp18->SetParLimits(1,0,0);
   mp18->SetParameter(2,19.73238);
   mp18->SetParError(2,0.03941474);
   mp18->SetParLimits(2,0,0);
   mp18->SetParameter(3,5.571993);
   mp18->SetParError(3,0.3191974);
   mp18->SetParLimits(3,1,20);
   mp18->SetParameter(4,-1.713048);
   mp18->SetParError(4,2.143647);
   mp18->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp18);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
