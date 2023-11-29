
/// \file in_place_dialog.cpp
/// Example of constructing widget in place.

#include "ull/ull.hpp"
#include <QApplication>


namespace ui = ull;


int main(int argc, char * argv[]) {
    QApplication app{argc, argv};

    auto dlg = ui::dialog {
        ui::vbox {
            ui::hbox {
                ui::label {
                    ui::text("Counter:")
                },
                ui::line_edit {
                    ui::id<"counter">,
                    ui::text("0")
                }
            },
            ui::button {
                ui::text("Button"),
                ui::on_click { [](auto & root) {
                    auto & edit = root.template child<"counter">();
                    edit.set_text(std::to_wstring(std::stoi(edit.text()) + 1));
                } }
            }
        }
    };

    dlg.show();

    return app.exec();
}
