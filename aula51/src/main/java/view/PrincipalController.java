package view;

import Model.Medida;
import java.net.URL;
import java.text.DecimalFormatSymbols;
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class PrincipalController implements Initializable {

    private final char ds = new DecimalFormatSymbols(Locale.getDefault(Locale.Category.FORMAT)).getDecimalSeparator();
    private final NumberFormat nf = NumberFormat.getInstance(Locale.getDefault());

    private boolean ehDe = true;
    private double fator = 1;

    private List<Medida> medidas = new ArrayList<>();

    @FXML
    private ComboBox<Medida> cmbbxMedidas;

    @FXML
    private TextField txtfldValorDe;

    @FXML
    private TextField txtfldValorPara;

    @FXML
    private Label lblUnDe;

    @FXML
    private Label lblUnPara;

    @FXML
    private ImageView imgvwSetas;

    @FXML
    private void btnFecharClick() {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION,
                "Deseja realmente sair?",
                ButtonType.YES, ButtonType.NO);
        alert.setTitle("Converte Medida");
        alert.showAndWait();
        if (alert.getResult() == ButtonType.YES) {
            System.exit(0);
        }
    }

    private String conversao(double val) {
        double v;
        if (ehDe) {
            v = val * fator;
        } else {
            v = val / fator;
        }
        return nf.format(v);
    }

    private void atualizaTxtFld() {
        if (ehDe) {
            try {
                if (!txtfldValorDe.getText().isEmpty()) {
                    txtfldValorPara.setText(conversao(nf.parse(txtfldValorDe.getText()).doubleValue()));
                } else {
                    txtfldValorPara.setText("");
                }
            } catch (ParseException ex) {
                Logger.getLogger(PrincipalController.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            try {
                if (!txtfldValorPara.getText().isEmpty()) {
                    txtfldValorDe.setText(conversao(nf.parse(txtfldValorPara.getText()).doubleValue()));
                } else {
                    txtfldValorDe.setText("");
                }
            } catch (ParseException ex) {
                Logger.getLogger(PrincipalController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

    }

    private final ChangeListener<? super String> listenerDe
            = (observable, oldValue, newValue) -> {
                if (!newValue.matches("\\d*(\\" + ds + "\\d*)?") && !newValue.isEmpty()) {
                    txtfldValorDe.setText(oldValue);
                } else {
                    atualizaTxtFld();
                }
            };

    private final ChangeListener<? super String> listenerPara
            = (observable, oldValue, newValue) -> {
                if (!newValue.matches("\\d*(\\" + ds + "\\d*)?") && !newValue.isEmpty()) {
                    txtfldValorPara.setText(oldValue);
                } else {
                    atualizaTxtFld();
                }
            };

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        Image setasEsq = new Image("/image/SetasEsquerda.png");
        Image setasDir = new Image("/image/SetasDireita.png");

        imgvwSetas.setImage(new Image("/image/SetasNenhum.png"));

        medidas.add(new Medida("Quilômetro", "Km", "Metro", "M", 1000));
        medidas.add(new Medida("Quilômetro", "Km", "Milha", "Mil", 0.62));
        medidas.add(new Medida("Metro", "M", "Polegada", "pol", 0.0254));
        medidas.add(new Medida("Metro", "M", "Centímetro", "cm", 100));
        medidas.add(new Medida("Polegada", "pol", "Centímetro", "cm", 2.54));

        cmbbxMedidas.setItems(FXCollections.observableList(medidas));

        cmbbxMedidas.valueProperty().addListener(
                new ChangeListener<Medida>() {
            @Override
            public void changed(ObservableValue<? extends Medida> observable,
                    Medida oldValue, Medida newValue) {
                fator = newValue.getFator();
                lblUnDe.setText(newValue.getSiglaDe());
                lblUnPara.setText(newValue.getSiglaPara());
                atualizaTxtFld();
            }
        });
        cmbbxMedidas.getSelectionModel().selectFirst();

        txtfldValorDe.focusedProperty().addListener(
                (ObservableValue<? extends Boolean> observable,
                        Boolean oldValue, Boolean newValue) -> {
                    if (newValue) { // objeto recebeu foco
                        ehDe = true;
                        imgvwSetas.setImage(setasDir);
                        txtfldValorDe.textProperty().addListener(listenerDe);
                    } else {
                        txtfldValorDe.textProperty().removeListener(listenerDe);
                    }
                });
        txtfldValorPara.focusedProperty().addListener(
                (ObservableValue<? extends Boolean> observable,
                        Boolean oldValue, Boolean newValue) -> {
                    if (newValue) { // objeto recebeu foco
                        ehDe = false;
                        imgvwSetas.setImage(setasEsq);
                        txtfldValorPara.textProperty().addListener(listenerPara);
                    } else {
                        txtfldValorPara.textProperty().removeListener(listenerPara);
                    }
                });

    }
}