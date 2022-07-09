
# include <Siv3D.hpp>

namespace Config
{
# if SIV3D_PLATFORM(WINDOWS)
	const FilePath BrowserPath = U"C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe";

# elif SIV3D_PLATFORM(MACOS)

	const FilePath BrowserPath = U"/Applications/Google Chrome.app/Contents/MacOS/Google Chrome";

# endif

}




void Main()
{
	// 縁の半径
	const int size = 150;
	// 針の太さのベース（時針の太さ）
	const int thick = 4;
	// 時刻用のフォント
	const Font hourFont(20);

	// 背景を色に
	Scene::SetBackground(ColorF(0.3,0.6,1.0));

	//絵文字
	const Texture Horse(Emoji(U"🐎"));

	//回転変数
	const int rota = 1;

	Window::SetTitle(U"競馬確認アプリ");

	while (System::Update())
	{
		// 中心の座標
		const auto center = Point(160, 160);

		// 縁に秒単位の線を描画
		for (auto i : step(60))
		{
			// 角度
			const double theta = i * 6_deg;
			// 時刻を描画するか
			const bool isHour = i % 5 == 0;
			// 描画する座標
			const Vec2 pos = OffsetCircular(center, size, theta);

			if (isHour)
			{
				// i == 0の場合は12を描画
				const String hourString = i == 0 ? U"12" : ToString(i / 5);
				hourFont(hourString).drawAt(pos.lerp(center, 0.2), Palette::White);
			}

			// 線を描画
			Line(pos, pos.lerp(center, isHour ? 0.1 : 0.03)).draw(thick / 2, isHour ? Palette::White : Palette::Lightgrey);
		}

		// 縁の描画
		Circle(center, size).drawFrame(thick / 2, Palette::White);

		// 現在時刻を取得
		const DateTime now = DateTime::Now();

		// 秒針を描画
		Line(center, OffsetCircular(center, size * 0.9, now.second * 6_deg)).draw(thick / 3, Palette::Yellow);
		// 分針を描画
		Line(center, OffsetCircular(center, size * 0.85, now.minute * 6_deg)).draw(thick / 2, Palette::White);
		// 時針を描画
		Line(center, OffsetCircular(center, size * 0.6, (now.hour % 12 + now.minute / 60.0) * 30_deg)).draw(thick, Palette::White);

		// 針の中心に円を描画
		Circle(center, size * 0.03).draw(Palette::White);



		//競馬情報確認ボタン
		if (SimpleGUI::Button(U"レース情報", Vec2(50, 350),200))
		{
			//Scene::SetBackground(ColorF(0.8, 0.1, 0.1));
			ChildProcess{ Config::BrowserPath,U"https://www.netkeiba.com/?rf=logo"};
		}

		//レース日程
		if (SimpleGUI::Button(U"レーシングカレンダー", Vec2(50, 400), 200))
		{
			//Scene::SetBackground(ColorF(0.8, 0.1, 0.1));
			ChildProcess{ Config::BrowserPath,U"https://www.jra.go.jp/keiba/calendar/" };
		}

		//阪神競馬場
		if (SimpleGUI::Button(U"阪神競馬場", Vec2(500, 100), 200))
		{
			//Scene::SetBackground(ColorF(0.8, 0.1, 0.1));
			ChildProcess{ Config::BrowserPath,U"https://www.jra.go.jp/facilities/race/hanshin/" };
		}
		
		//京都競馬場
		if (SimpleGUI::Button(U"京都競馬場", Vec2(500, 150), 200))
		{
			//Scene::SetBackground(ColorF(0.8, 0.1, 0.1));
			ChildProcess{ Config::BrowserPath,U"https://www.jra.go.jp/facilities/race/kyoto/" };
		}


		//中京競馬場

		if (SimpleGUI::Button(U"中京競馬場", Vec2(500, 200), 200))
		{
			//Scene::SetBackground(ColorF(0.8, 0.1, 0.1));
			ChildProcess{ Config::BrowserPath,U"https://www.jra.go.jp/facilities/race/chukyo/" };
		}
		
		//東京競馬場

		if (SimpleGUI::Button(U"東京競馬場", Vec2(500, 250), 200))
		{
			//Scene::SetBackground(ColorF(0.8, 0.1, 0.1));
			ChildProcess{ Config::BrowserPath,U"https://www.jra.go.jp/facilities/race/tokyo/" };
		}

		//中山競馬場

		if (SimpleGUI::Button(U"中山競馬場", Vec2(500, 300), 200))
		{
			//Scene::SetBackground(ColorF(0.8, 0.1, 0.1));
			ChildProcess{ Config::BrowserPath,U"https://www.jra.go.jp/facilities/race/nakayama/" };
		}



		//テクスチャの回転
		//Horse.scaled(1.5).drawAt(550,450);
		Horse.rotated(Scene::Time() * rota).drawAt(550,450);

	}
}



