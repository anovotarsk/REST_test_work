#include "MainForm.h"

namespace RESTtest {

    void MainForm::HideAllPositions() {
        position1->Visible = false;
        position2->Visible = false;
        position3->Visible = false;
        position4->Visible = false;
        position5->Visible = false;
        position6->Visible = false;
        position7->Visible = false;
        position8->Visible = false;

        position1->Checked = false;
        position2->Checked = false;
        position3->Checked = false;
        position4->Checked = false;
        position5->Checked = false;
        position6->Checked = false;
        position7->Checked = false;
        position8->Checked = false;
    }

    void MainForm::FillPosition(RadioButton^ position, Json::Value& value, int index) {
        if (int(value["positions"].size()) < index)
            return;

        position->Visible = true;
        position->Text = gcnew String(std::string(value["positions"][index - 1]["name"].asCString()).c_str());
    }

    void MainForm::HideAllUsersPanels() {
        userPanel1->Visible = false;
        userPanel2->Visible = false;
        userPanel3->Visible = false;
        userPanel4->Visible = false;
        userPanel5->Visible = false;
        userPanel6->Visible = false;
    }

    void MainForm::FillUserPanel(Panel^ panel, Label^ name, Label^ position,
        Label^ email, Label^ phone, PictureBox^ photo,
        Json::Value& json_users, Json::Value::ArrayIndex id) {

        size_t http_code;


        try {
            http_code = RESTClient::get_picture_to_file("tmp.jpg", json_users["users"][id]["photo"].asCString());
        }
        catch (std::string e) {
            String^ message = gcnew String(e.c_str());
            MessageBox::Show(message);
            exit(0);
        }

        if (http_code == 200) {
            Net::WebRequest^ request_img = Net::WebRequest::Create(gcnew String(json_users["users"][id]["photo"].asCString()));
            IO::Stream^ stream = request_img->GetResponse()->GetResponseStream();

            photo->Image = gcnew Bitmap(stream);
            photo->Visible = true;
        }
        else {
            photo->Visible = false;
        }

        panel->Visible = true;
        name->Text = gcnew String(json_users["users"][id]["name"].asCString());
        position->Text = gcnew String(json_users["users"][id]["position"].asCString());
        email->Text = gcnew String(json_users["users"][id]["email"].asCString());
        phone->Text = gcnew String(json_users["users"][id]["phone"].asCString());
    }

    void MainForm::FillUsersPage(bool from_first) {
        static int page = 1;
        std::string users_responce;

        if (from_first)
            page = 1;

        try {
            users_responce = RESTClient::get_users(page, 6);
        }
        catch (std::string e) {
            String^ message = gcnew String(e.c_str());
            MessageBox::Show(message);
            exit(0);
        }

        Json::Reader reader;
        Json::Value json_users;

        reader.parse(users_responce, json_users);

        if (page >= json_users["total_pages"].asInt()) {
            page = 1;
        }
        else {
            page++;
        }

        HideAllUsersPanels();

        size_t users_count = json_users["count"].asInt();

        if (users_count >= 1) {
            FillUserPanel(userPanel1, userName1, userPosition1,
                userEmail1, userPhone1, userPhoto1, json_users, 0);
        }
        if (users_count >= 2) {
            FillUserPanel(userPanel2, userName2, userPosition2,
                userEmail2, userPhone2, userPhoto2, json_users, 1);
        }
        if (users_count >= 3) {
            FillUserPanel(userPanel3, userName3, userPosition3,
                userEmail3, userPhone3, userPhoto3, json_users, 2);
        }
        if (users_count >= 4) {
            FillUserPanel(userPanel4, userName4, userPosition4,
                userEmail4, userPhone4, userPhoto4, json_users, 3);
        }
        if (users_count >= 5) {
            FillUserPanel(userPanel5, userName5, userPosition5,
                userEmail5, userPhone5, userPhoto5, json_users, 4);
        }
        if (users_count >= 6) {
            FillUserPanel(userPanel6, userName6, userPosition6,
                userEmail6, userPhone6, userPhoto6, json_users, 5);
        }
    }

    bool MainForm::IsValidName() {
        if (nameTextBox->Text->Length < 2 || nameTextBox->Text->Length > 60)
            return false;

        return true;
    }

    bool MainForm::IsValidEmail() {
        std::regex validator("[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[A-Za-z0-9](?:[A-Za-z0-9-]*[A-Za-z0-9])?\\.)+[A-Za-z0-9](?:[A-Za-z0-9-]*[A-Za-z0-9])?");
        std::string text = msclr::interop::marshal_as<std::string>(emailTextBox->Text);

        if (std::regex_match(text.c_str(), validator))
            return true;

        return false;
    }

    bool MainForm::IsValidPhone() {
        std::regex validator("\\+38 \\(0\\d\\d\\) \\d\\d\\d - \\d\\d - \\d\\d");
        std::string text = msclr::interop::marshal_as<std::string>(phoneTextBox->Text);

        if (std::regex_match(text.c_str(), validator))
            return true;

        return false;
    }

    bool MainForm::IsVisiablePositionSelected() {
        bool selected = false;

        if (position1->Visible && position1->Checked)
            selected = true;
        else if (position2->Visible && position2->Checked)
            selected = true;
        else if (position3->Visible && position3->Checked)
            selected = true;
        else if (position4->Visible && position4->Checked)
            selected = true;
        else if (position5->Visible && position5->Checked)
            selected = true;
        else if (position6->Visible && position6->Checked)
            selected = true;
        else if (position7->Visible && position7->Checked)
            selected = true;
        else if (position8->Visible && position8->Checked)
            selected = true;

        return selected;
    }

    bool MainForm::IsValidPhotoChoosed() {
        std::string file_name = msclr::interop::marshal_as<std::string>(photoTextBox->Text);
        size_t point_position = file_name.rfind('.');
        std::ifstream fd;
        std::string ext;

        if (point_position == std::string::npos)
            return false;

        ext = file_name.substr(point_position);

        if (ext != ".jpg" && ext != ".jpeg")
            return false;

        fd.open(file_name);

        if (fd.is_open()) {
            fd.close();
            return true;
        }

        return false;
    }

    void MainForm::FormatText(std::string& str, int index, char c) {
        if (str.length() > index && str[index] != c) {
            str.insert(index, &c);
        }
    }

    bool MainForm::ifNotDigit(const char& c) {
        std::string digits("0123456789");

        if (digits.find(c) == std::string::npos) {
            return true;
        }

        return false;
    }

    bool MainForm::EnteredDataChecks() {
        if (!IsValidName()) {
            MessageBox::Show("Invalid name");
            return false;
        }

        if (!IsValidEmail()) {
            MessageBox::Show("Invalid email");
            return false;
        }

        if (!IsValidPhone()) {
            MessageBox::Show("Invalid phone");
            return false;
        }

        if (!IsVisiablePositionSelected()) {
            MessageBox::Show("Please, select position");
            return false;
        }

        if (!IsValidPhotoChoosed()) {
            MessageBox::Show("Invalid photo");
            return false;
        }

        return true;
    }

    size_t MainForm::GetSelectedPositionId() {
        size_t position_id = 0;
        std::string position_name = "";
        Json::Reader reader;
        Json::Value json_positions;


        if (position1->Visible && position1->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position1->Text);
        else if (position2->Visible && position2->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position2->Text);
        else if (position3->Visible && position3->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position3->Text);
        else if (position4->Visible && position4->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position4->Text);
        else if (position5->Visible && position5->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position5->Text);
        else if (position6->Visible && position6->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position6->Text);
        else if (position7->Visible && position7->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position7->Text);
        else if (position8->Visible && position8->Checked)
            position_name = msclr::interop::marshal_as<std::string>(position8->Text);

        try {
            reader.parse(RESTClient::get_positions(), json_positions);
        }
        catch (std::string e) {
            String^ message = gcnew String(e.c_str());
            MessageBox::Show(message);
            exit(0);
        }

        for (int i = 0; i < int(json_positions["positions"].size()); i++) {
            if (position_name == json_positions["positions"][i]["name"].asCString()) {
                position_id = json_positions["positions"][i]["id"].asInt();
                break;
            }
        }

        return position_id;
    }

}
