package view;

import static Config.Config.ALTERAR;
import static Config.Config.EXCLUIR;
import static Config.Config.INCLUIR;
import static DAO.DAO.academicoRepository;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import org.springframework.data.domain.Sort;

public class CRUDAcademicoController implements Initializable {

    private AcademicoController controllerPai;

    @FXML
    private AnchorPane anchorPane;

    @FXML
    private TextField txtfldRA;

    @FXML
    private TextField txtfldNome;

    @FXML
    private TextField txtfldEmail;

    @FXML
    private Button btnConfirma;

    @FXML
    private Button btnCancela;

    @FXML
    private void btnCancelaClick() {
        anchorPane.getScene().getWindow().hide();
        controllerPai.tblvwAcademicos.requestFocus();
    }

    @FXML
    private void btnConfirmaClick() {
        controllerPai.academico.setRa(txtfldRA.getText());
        controllerPai.academico.setNome(txtfldNome.getText());
        controllerPai.academico.setEmail(txtfldEmail.getText());
        try {
            switch (controllerPai.acao) {
                case INCLUIR:
                    academicoRepository.insert(controllerPai.academico);
                    break;
                case ALTERAR:
                    academicoRepository.save(controllerPai.academico);
                    break;
                case EXCLUIR:
                    academicoRepository.delete(controllerPai.academico);
                    break;
            }
            controllerPai.tblvwAcademicos.setItems(FXCollections.observableList(academicoRepository.findAll(new Sort(new Sort.Order("nome")))));
            controllerPai.tblvwAcademicos.refresh();
            anchorPane.getScene().getWindow().hide();
        } catch (Exception e) {
            Alert alert = new Alert(AlertType.ERROR);
            alert.setTitle("Erro");
            alert.setHeaderText("Cadastro de Acadêmico");
            if (e.getMessage().contains("duplicate key")) {
                alert.setContentText("RA já cadastrado");
            } else {
                alert.setContentText(e.getMessage());
            }
            alert.showAndWait();
        }
    }

    public void setCadastroController(AcademicoController controllerPai) {
        this.controllerPai = controllerPai;
        txtfldRA.setText(controllerPai.academico.getRa());
        txtfldNome.setText(controllerPai.academico.getNome());
        txtfldEmail.setText(controllerPai.academico.getEmail());

        txtfldRA.setDisable(controllerPai.acao == EXCLUIR);
        txtfldNome.setDisable(controllerPai.acao == EXCLUIR);
        txtfldEmail.setDisable(controllerPai.acao == EXCLUIR);
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {

    }
}
