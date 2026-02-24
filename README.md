# Arduino Combo Master (格鬥指令辨識系統) 🕹️

## 📝 專案簡介
[cite_start]本專案在 Arduino Mega 環境下實作了一個「格鬥遊戲招式偵測系統」。玩家可以透過 **4x4 矩陣鍵盤** 或 **雙軸搖桿** 輸入指令，系統會即時比對內建的招式表（如：下、斜右下、右、拳），並透過 **8x8 LED 點矩陣** 與 **LCD 螢幕** 提供視覺回饋 [cite: 59, 72, 85]。

## 🛠️ 技術核心
- [cite_start]**即時指令緩衝區 (Real-time Input Buffer)**: 實作長度為 4 的陣列來記錄玩家的輸入歷史 [cite: 57, 77]。
- [cite_start]**招式序列偵測 (Combo Sequence Matching)**: 透過狀態索引（Sequence Index）追蹤玩家輸入是否符合特定招式路徑（如 `D->r->R->P`） [cite: 58, 83]。
- **硬體整合開發**: 
    - [cite_start]使用 **74LS138** 解碼器進行 8x8 LED 多工掃描顯示 [cite: 71, 74]。
    - [cite_start]整合 **ADC (類比數位轉換)** 讀取搖桿數值並轉譯為方向指令 [cite: 92, 93]。
    - [cite_start]**LiquidCrystal** 庫實作 UI 介面，同步顯示輸入紀錄 [cite: 72, 79]。

## 🎮 招式表設計 (Command List)
| 招式名稱 | 指令序列 (Input Sequence) | LED 動作代號 |
| :--- | :--- | :--- |
| 招式 A | [cite_start]下(D) -> 斜右下(r) -> 右(R) -> 拳(P)  [cite_start]| word_to_led(3, 0) [cite: 84] |
| 招式 B | [cite_start]右(R) -> 下(D) -> 斜右下(r) -> 拳(P)  [cite_start]| word_to_led(2, 1) [cite: 87] |
| 招式 C | [cite_start]下(D) -> 斜左下(l) -> 左(L) -> 踢(K) [cite: 59] [cite_start]| word_to_led(4, 5) [cite: 90] |
