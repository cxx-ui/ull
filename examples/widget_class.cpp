
/// \file in_place_dialog.cpp
/// Example of defining class for widget.

#include "ull/ull.hpp"
#include "ull/qt/platform_widget.hpp"
#include <QApplication>


namespace ui = ull;


class caption: public ui::basic_property<std::string> {
public:
    template <typename ... Args>
    requires (std::constructible_from<std::string, Args...>)
    caption(Args && ... args):
        ui::basic_property<std::string>(std::forward<Args>(args)...) {}
};


class user_defined_widget_base: public ui::widget_base {
public:
    user_defined_widget_base() {
        auto & layout = set_layout(*this,
            ui::vbox {
                ui::hbox {
                    ui::label {
                        ui::id<"caption">,
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
        );

        caption_ = &layout.template child<"caption">();
    }

    /// Sets counter widget caption
    void set_caption(const std::string & s) {
        caption_->set_text(s);
    }

private:
    ui::label_base * caption_ = nullptr;
};


template <typename ... Elements>
using user_defined_widget = ull::widget_t<user_defined_widget_base, Elements...>;


void apply(user_defined_widget_base & w, caption & c) {
    w.set_caption(c.value());
}


int main(int argc, char * argv[]) {
    QApplication app{argc, argv};

    auto dlg = ui::dialog {
        ui::vbox {
            user_defined_widget {
                caption("ZZZZZ")
            }
        }
    };

    dlg.show();

    return app.exec();
}
